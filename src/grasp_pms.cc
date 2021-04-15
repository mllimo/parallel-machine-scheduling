#include <grasp_pms.h>

GraspPms::GraspPms() {
  lrc_size = 2;
  is_first_run = true;
  this->max_iteration_no_improvement = 3;
  iterations_no_improvement = 0;
}

GraspPms::GraspPms(size_t lrc_size, size_t max_iteration_no_improvement) {
  this->lrc_size = lrc_size;
  is_first_run = true;
  this->max_iteration_no_improvement = max_iteration_no_improvement;
  iterations_no_improvement = 0;
}

GraspPms::~GraspPms() {}

std::vector<Machine> GraspPms::Solve(size_t machines,
                                     std::vector<std::vector<int>>& setup_times,
                                     std::vector<int>& jobs_times) {
  // Preprocesamiento
  std::vector<Machine> solution(machines, Machine(&jobs_times, &setup_times));
  std::vector<Machine> best_solution = solution;
  ResetExecuted(jobs_times.size());

  for (auto& machine : solution) {
    machine.Insert(GetFirstJob(jobs_times, setup_times));
  }

  // Buscar criterio de parada: Iteraciones sin mejora por ejemplo
  while (iterations_no_improvement < max_iteration_no_improvement) {
    // Fase construvtiva
    Construct(solution, jobs_times);
    // Busqueda Local
    
    // Actualizar la solucion
    UpdateSolution(solution, best_solution);
    // Reseteo
    solution.resize(machines, Machine(&jobs_times, &setup_times));
    ResetExecuted(jobs_times.size());
  }
  return best_solution;
}

size_t GraspPms::SelectionRandom(std::vector<int>& rcl) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<size_t> distrib(0, rcl.size() - 1);
  return rcl[distrib(gen)];
}

std::vector<int> GraspPms::MakeRcl(std::vector<int>& jobs_times,
                                   Machine& machine) {
  std::vector<int> best_candidates;
  for (size_t i = 0; i < lrc_size && !IsAllVisited(); ++i) {
    best_candidates.push_back(Selection(jobs_times, machine));
  }
  return best_candidates;
}

void GraspPms::Construct(std::vector<Machine>& machines,
                         std::vector<int>& jobs_times) {
  std::vector<int> rcl;
  size_t candidate;
  while (!IsAllVisited()) {
    for (auto& machine : machines) {
      rcl = MakeRcl(jobs_times, machine);
      if (rcl.size() == 0) break;
      candidate = SelectionRandom(rcl);
      is_executed[candidate] = true;
      machine.Insert(candidate);
    }
  }
}

void GraspPms::UpdateSolution(std::vector<Machine>& actual_solution,
                              std::vector<Machine>& best_solution) {
  if (actual_solution < best_solution || is_first_run) {
    best_solution = actual_solution;
    iterations_no_improvement = 0;
    is_first_run = false;
  } else {
    ++iterations_no_improvement;
  }
}
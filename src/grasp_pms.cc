#include <grasp_pms.h>

GraspPms::GraspPms() { lrc_size = 2; }

GraspPms::GraspPms(size_t lrc_size, StopCondition* stop_condition_, LocalSearch* local_search_) {
  this->lrc_size = lrc_size;
  local_search = local_search_;
  stop_condition = stop_condition_;
}

GraspPms::~GraspPms() {
  if (local_search != NULL) delete local_search;
  if (stop_condition != NULL) delete stop_condition;
}

std::vector<Machine> GraspPms::Solve(size_t machines, std::vector<std::vector<int>>& setup_times,
                                     std::vector<int>& jobs_times) {
  // Preprocesamiento
  actual_solution.resize(machines, Machine(&jobs_times, &setup_times));
  best_solution = actual_solution;

  ResetExecuted(jobs_times.size());

  for (auto& machine : actual_solution) {
    machine.Insert(GetFirstJob(jobs_times, setup_times));
  }

  do {
    // Reseteo
    ResetExecuted(jobs_times.size());
    // Fase construvtiva
    Construct(actual_solution, jobs_times);
    // Busqueda Local
    Local(actual_solution);
  } while ((*stop_condition)(this));  // Actualizar la solucion + comprobar condicion

  return best_solution;
}

size_t GraspPms::SelectionRandom(std::vector<int>& rcl) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<size_t> distrib(0, rcl.size() - 1);
  return rcl[distrib(gen)];
}

std::vector<int> GraspPms::MakeRcl(std::vector<int>& jobs_times, Machine& machine) {
  std::vector<int> best_candidates;
  for (size_t i = 0; i < lrc_size && !IsAllVisited(); ++i) {
    best_candidates.push_back(Selection(jobs_times, machine));
  }
  return best_candidates;
}

void GraspPms::Construct(std::vector<Machine>& machines, std::vector<int>& jobs_times) {
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

void GraspPms::Local(std::vector<Machine>& solution) {
  if (local_search == NULL) return;
  std::vector<Machine> best_local_solution = solution;
  do {
    (*local_search)(solution);
    if (solution < best_local_solution) {
      best_local_solution = solution;
    }
  } while (solution != best_local_solution);
}
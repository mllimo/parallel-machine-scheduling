#include <grasp_pms.h>

GraspPms::GraspPms() { lrc_size = 2; }

GraspPms::GraspPms(size_t lrc_size) { this->lrc_size = lrc_size; }

GraspPms::~GraspPms() {}

std::vector<Machine> GraspPms::Solve(size_t machines,
                                     std::vector<std::vector<int>>& setup_times,
                                     std::vector<int>& jobs_times) {
  // Preprocesamiento
  std::vector<Machine> result(machines, Machine(&jobs_times, &setup_times));
  std::vector<Machine> best_result = result;
  is_executed.resize(jobs_times.size(), false);

  for (auto& machine : result) {
    machine.Insert(GetMinNotExecuted(jobs_times, setup_times));
  }

  // Buscar criterio de parada
  // Iteraciones sin mejora por ejemplo
  size_t max_iteration_no_improvement = 5;
  size_t iterations_no_improvement = 0;
  bool is_first = true;
  while (iterations_no_improvement < max_iteration_no_improvement) {
    // Fase construvtiva
    Construct(result, jobs_times);

    // Actualizar la solucion
    if (result < best_result || is_first) {
      best_result = result;
      iterations_no_improvement = 0;
      is_first = false;
    } else {
      ++iterations_no_improvement;
    }
    result.resize(machines, Machine(&jobs_times, &setup_times));
    is_executed.resize(jobs_times.size(), false);
    
  }
  return best_result;
}

bool GraspPms::AllVisited(const std::vector<bool>& visited) const {
  for (const auto& element : visited)
    if (element == false) return false;
  return true;
}

int GraspPms::GetMinNotExecuted(
    const std::vector<int>& jobs_times,
    const std::vector<std::vector<int>>& setup_times) {
  int min_tct = std::numeric_limits<int>::max();
  int actual_tct, min_index;
  for (size_t i = 0; i < jobs_times.size(); ++i) {
    actual_tct = jobs_times[i] + setup_times[0][i + 1];
    if (actual_tct < min_tct && !is_executed[i]) {
      min_index = i;
      min_tct = actual_tct;
    }
  }
  is_executed[min_index] = true;
  return min_index;
}

size_t GraspPms::Selection(std::vector<int>& jobs_times, Machine& machine) {
  size_t best_time = std::numeric_limits<size_t>::max();
  size_t j, min_index;
  for (j = 0; j < jobs_times.size(); ++j) {
    if (is_executed[j]) continue;
    if (machine.TctWithJob(j) < best_time) {
      min_index = j;
      best_time = machine.TctWithJob(j);
    }
  }
  return min_index;
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
  size_t selected;
  for (size_t i = 0; i < lrc_size; ++i) {
    if (AllVisited(is_executed)) break;
    selected = Selection(jobs_times, machine);
    if (is_executed[selected]) std::cerr << "Arreglar esto\n";
    best_candidates.push_back(selected);
  }
  return best_candidates;
}

void GraspPms::Construct(std::vector<Machine>& machines,
                         std::vector<int>& jobs_times) {
  std::vector<int> rcl;
  size_t candidate_chose;
  while (!AllVisited(is_executed)) {
    for (auto& machine : machines) {
      rcl = MakeRcl(jobs_times, machine);
      candidate_chose = SelectionRandom(rcl);
      is_executed[candidate_chose] = true;
      machine.Insert(candidate_chose);
    }
  }
}
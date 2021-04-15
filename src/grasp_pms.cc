#include <grasp_pms.h>

GraspPms::GraspPms() { lrc_size = 2; }

GraspPms::GraspPms(size_t lrc_size) { this->lrc_size = lrc_size; }

GraspPms::~GraspPms() {}

std::vector<Machine> GraspPms::Solve(size_t machines,
                                     std::vector<std::vector<int>>& setup_times,
                                     std::vector<int>& jobs_times) {
  // Preprocesamiento
  std::vector<Machine> result(machines, Machine(&jobs_times, &setup_times));
  is_executed.resize(jobs_times.size(), false);

  for (auto& machine : result) {
    machine.Insert(GetMinNotExecuted(jobs_times, setup_times));
  }

  // Buscar criterio de parada
  while (true) {
      // Fase construvtiva
      Construct(result, setup_times, jobs_times);
    }
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

size_t GraspPms::Selection(std::vector<std::vector<int>>& setup_times,
                           std::vector<int>& jobs_times, Machine& machine) {
  int best_time = std::numeric_limits<int>::max();
  size_t i, j, min_index;
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
  
}

std::vector<int> GraspPms::MakeRcl(std::vector<std::vector<int>>& setup_times,
                                   std::vector<int>& jobs_times,
                                   Machine& machine) {
  std::vector<int> best_candidates;
  size_t selected;
  for (size_t i = 0; i < lrc_size; ++i) {
    if (AllVisited(is_executed)) break;
    selected = Selection(setup_times, jobs_times, machine);
    if (is_executed[selected]) std::cerr << "Arreglar esto\n";
    best_candidates.push_back(selected);
  }
  return best_candidates;
  size_t machines
}

std::vector<Machine> GraspPms::Construct(
    std::vector<Machine>& machines, std::vector<std::vector<int>>& setup_times,
    std::vector<int>& jobs_times) {
  std::vector<int> rcl;
  while (!AllVisited(is_executed)) {
    for (auto& machine : machines) {
      rcl = MakeRcl(setup_times, jobs_times, machine);
    }
  }
}
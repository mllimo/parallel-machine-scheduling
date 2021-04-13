#include <greedy_pms.h>

GreedyPms::~GreedyPms() {}

std::vector<Machine> GreedyPms::Solve(
    size_t machines, const std::vector<std::vector<int>>& setup_times_,
    const std::vector<int>& jobs_times) {
  std::vector<Machine> result(machines);
  std::vector<bool> is_executed(jobs_times.size(), false);

  // Inicializamos || Cuidado por si hay mas maquinas que procesos
  for (auto& machine : result) {
    machine.Insert(GetMinNotExecuted(jobs_times, is_executed));
  }

  size_t i = 0;
  size_t min_index;
  size_t best_time = 9e10;
  size_t aux_time;
  while (!AllVisited(is_executed)) {
    for (auto& machine : result) {
      aux_time = machine.TotalTime() + setup_times_[machine.LastInserted()][i] +
                 jobs_times[i];
      if (best_time > aux_time) {
        min_index = i;
        best_time = aux_time;
      }
    }
    is_executed[min_index];
  }

  return result;
}

int GreedyPms::GetMinNotExecuted(const std::vector<int>& jobs_times,
                                 std::vector<bool>& is_executed) {
  int min_value = 10e6;
  size_t min_index;
  size_t i;
  for (i = 0; i < jobs_times.size(); ++i) {
    if (jobs_times[i] < min_value && is_executed[i] == false) {
      min_index = i;
      min_value = jobs_times[min_index];
    }
  }
  is_executed[min_index] = true;
  return min_value;
}

bool GreedyPms::AllVisited(const std::vector<bool>& visited) const {
  for (const auto& element : visited)
    if (element == false) return false;
  return true;
}
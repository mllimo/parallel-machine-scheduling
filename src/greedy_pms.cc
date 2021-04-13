#include <greedy_pms.h>

GreedyPms::~GreedyPms() {}

std::vector<Machine> GreedyPms::Solve(
    size_t machines, std::vector<std::vector<int>>& setup_times_,
    std::vector<int>& jobs_times) {
  std::vector<Machine> result(machines, Machine(&jobs_times, &setup_times_));
  std::vector<bool> is_executed(jobs_times.size(), false);

  // Inicializamos || Cuidado por si hay mas maquinas que procesos
  for (auto& machine : result) {
    machine.Insert(GetMinNotExecuted(jobs_times, is_executed));
  }

  size_t i, j, min_index, aux_time, best_time;
  while (!AllVisited(is_executed)) {
    for (i = 0; i < result.size(); ++i) {
      best_time = 9e10;
      min_index = -1;
      for (j = 0; j < jobs_times.size(); ++j) {
        if (is_executed[j] == true) continue;
        aux_time = result[i].TotalTime() + setup_times_[result[i].LastInserted()][j] + jobs_times[j];
        if (best_time > aux_time) {
          min_index = j;
          best_time = aux_time;
        }
      }
      result[i].Insert(min_index);
      is_executed[min_index] = true;;
    }
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
  return min_index;
}

bool GreedyPms::AllVisited(const std::vector<bool>& visited) const {
  for (const auto& element : visited)
    if (element == false) return false;
  return true;
}
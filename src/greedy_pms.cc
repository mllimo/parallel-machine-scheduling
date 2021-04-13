#include <greedy_pms.h>

GreedyPms::~GreedyPms() {}

std::vector<Machine> GreedyPms::Solve(
    size_t machines, std::vector<std::vector<int>>& setup_times,
    std::vector<int>& jobs_times) {
  // Nuestro conjunto de soluciones y el conjunto para seleccionar
  std::vector<Machine> result(machines, Machine(&jobs_times, &setup_times));
  std::vector<bool> is_executed(jobs_times.size(), false);

  // Inicializamos || Cuidado por si hay mas maquinas que procesos-
  for (auto& machine : result) {
    machine.Insert(GetMinNotExecuted(jobs_times, setup_times, is_executed));
  }

  size_t i, j, min_index, best_time;
  while (!AllVisited(is_executed)) {
    for (i = 0; i < result.size(); ++i) {
      best_time = std::numeric_limits<int>::max();
      for (j = 0; j < jobs_times.size(); ++j) {
        if (is_executed[j]) continue;
        if (result[i].TctWithJob(j) < best_time) {
          min_index = j;
          best_time = result[i].TctWithJob(j);
        }
      }
      if (!is_executed[min_index]) {
        result[i].Insert(min_index);
        is_executed[min_index] = true;
      }
    }
  }

  return result;
}

int GreedyPms::GetMinNotExecuted(
    const std::vector<int>& jobs_times,
    const std::vector<std::vector<int>>& setup_times,
    std::vector<bool>& is_executed) {
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

bool GreedyPms::AllVisited(const std::vector<bool>& visited) const {
  for (const auto& element : visited)
    if (element == false) return false;
  return true;
}
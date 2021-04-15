#include <greedy_pms.h>

GreedyPms::~GreedyPms() {}

std::vector<Machine> GreedyPms::Solve(
    size_t machines, std::vector<std::vector<int>>& setup_times,
    std::vector<int>& jobs_times) {
  // Preprocesamiento
  std::vector<Machine> vector_machines(machines, Machine(&jobs_times, &setup_times));
  ResetExecuted(jobs_times.size());

  for (auto& machine : vector_machines) {
    machine.Insert(GetFirstJob(jobs_times, setup_times));
  }

  size_t candidate;
  while (!IsAllVisited()) {
    for (auto& machine : vector_machines) {
      candidate = Selection(jobs_times, machine);
      is_executed[candidate] = true;
      machine.Insert(candidate);
    }
  }

  return vector_machines;
}

size_t GreedyPms::GetFirstJob(
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

size_t GreedyPms::Selection(std::vector<int>& jobs_times, Machine& machine) {
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

bool GreedyPms::IsAllVisited() const {
  for (const auto& element : is_executed)
    if (element == false) return false;
  return true;
}

void  GreedyPms::ResetExecuted(size_t size) {
  is_executed.resize(size, false);
}
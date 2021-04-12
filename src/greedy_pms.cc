#include <greedy_pms.h>

GreedyPms::~GreedyPms() {}

std::vector<Machine> GreedyPms::Solve(
    size_t machines, const std::vector<std::vector<int>>& setup_times_,
    const std::vector<int>& process_times) {
  std::vector<Machine> result;
  std::vector<std::vector<bool>> executed(setup_times_.size(), std::vector<bool>(setup_times_.size(), false));
  

  return result;
}
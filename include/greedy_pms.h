#ifndef GREEDY_H
#define GREEDY_H

#include <strategy_pms.h>

/**
 * @brief Estrategia para resolver el problma PSM con una metodología Greedy
 */
class GreedyPms : public StrategyPms {
 public:
  ~GreedyPms();
  std::vector<std::vector<int>> Solve(
      size_t machines, const std::vector<std::vector<int>>& setup_times_,
      const std::vector<int>& process_times);
};

#endif
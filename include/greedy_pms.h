#ifndef GREEDY_H
#define GREEDY_H

#include <strategy_pms.h>
#include <algorithm>

/**
 * @brief Estrategia para resolver el problma PSM con una metodología Greedy
 */
class GreedyPms : public StrategyPms {
 public:
  ~GreedyPms();
  std::vector<Machine> Solve(size_t machines,
                             std::vector<std::vector<int>>& setup_times,
                             std::vector<int>& jobs_times);

 protected:
  int GetMinNotExecuted(const std::vector<int>& jobs_times,
                        const std::vector<std::vector<int>>& setup_times,
                        std::vector<bool>& is_executed);

  bool AllVisited(const std::vector<bool>& visited) const;
};

#endif
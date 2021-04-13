#ifndef GREEDY_H
#define GREEDY_H

#include <strategy_pms.h>
#include <machine.h>
#include <algorithm>

/**
 * @brief Estrategia para resolver el problma PSM con una metodología Greedy
 */
class GreedyPms : public StrategyPms {
 public:
  ~GreedyPms();
  std::vector<Machine> Solve(size_t machines,
                             const std::vector<std::vector<int>>& setup_times_,
                             const std::vector<int>& jobs_times);

 protected:
  int GetMinNotExecuted(const std::vector<int>& jobs_times,
                        std::vector<bool>& is_executed);

  bool AllVisited(const std::vector<bool>& visited) const;
};

#endif
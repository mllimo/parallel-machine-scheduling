#ifndef GREEDY_H
#define GREEDY_H

#include <strategy_pms.h>

#include <algorithm>

/**
 * @brief Estrategia para resolver el problma PSM con una metodología Greedy
 */
class GreedyPms : public StrategyPms {
 public:
  virtual ~GreedyPms();
  virtual std::vector<Machine> Solve(size_t machines,
                                     std::vector<std::vector<int>>& setup_times,
                                     std::vector<int>& jobs_times);

 protected:
  std::vector<bool> is_executed;

  virtual size_t GetFirstJob(const std::vector<int>& jobs_times,
                     const std::vector<std::vector<int>>& setup_times);

  virtual size_t Selection(std::vector<int>& jobs_times, Machine& machine);

  bool IsAllVisited() const;
  void ResetExecuted(size_t size);
};

#endif
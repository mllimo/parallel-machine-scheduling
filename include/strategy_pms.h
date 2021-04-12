#ifndef STRATEGY_PMS_H
#define STRATEGY_PMS_H

#include <iostream>
#include <vector>

class StrategyPms {
 public:
  virtual ~StrategyPms();
  virtual std::vector<std::vector<int>> Solve(
      size_t machines, const std::vector<std::vector<int>>& setup_times_,
      const std::vector<int>& process_times) = 0;
};

#endif
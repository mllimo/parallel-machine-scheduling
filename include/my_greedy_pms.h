#ifndef MY_GREEDY_PMS_H
#define MY_GREEDY_PMS_H

#include <strategy_pms.h>

class MyGreedyPms : public StrategyPms {
 public:
  MyGreedyPms();
  ~MyGreedyPms();
  std::vector<Machine> Solve(size_t machines,
                             std::vector<std::vector<int>>& setup_times,
                             std::vector<int>& jobs_times);

 protected:
  size_t GetFirstJob(std::vector<std::vector<int>>& setup_times,
                     std::vector<int>& jobs_times,
                     std::vector<bool>& is_executed);

  size_t Selection(std::vector<std::vector<int>>& setup_times,
                   std::vector<int>& jobs_times, std::vector<bool>& is_executed,
                   Machine& machine);

  bool IsAllVisited(const std::vector<bool>& visited) const;
};

#endif
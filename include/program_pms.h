#ifndef PROGRAM_PMS_H
#define PROGRAM_PMS_H

#include <grasp_pms.h>
#include <greedy_pms.h>
#include <my_greedy_pms.h>
#include <problem_pms.h>
#include <program.h>
#include <reinsert_entre.h>
#include <reinsert_intra.h>
#include <stop_max_iteration.h>
#include <stop_no_improvement.h>
#include <swap_entre.h>
#include <swap_intra.h>
#include <timer.h>

#include <map>
#include <functional>

class ProgramPms : public Program {
 public:
  using Program::Program;
  ~ProgramPms();

  int Run();
  void ShowUsage() const;

 private:
  StrategyPms* GetStrategy(const std::string& algorithm);
  LocalSearch* GetLocalSearch(const std::string& local_search);
  StopCondition* GetStopCondition(const std::string& stop_condition, size_t iterations);
};

#endif
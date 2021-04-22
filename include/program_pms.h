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
#include <gvns.h>
#include <vnd.h>

#include <functional>
#include <string>
#include <vector>
#include <map>

class ProgramPms : public Program {
 public:
  using Program::Program;
  virtual ~ProgramPms();

  virtual int Run();
  virtual void ShowUsage() const;

 protected:
  StrategyPms* algorithm;
  LocalSearch* local_seach;
  StopCondition* stop_condition;
  Gvns* gvns;
  Vnd* vnd;
  std::vector<LocalSearch*> local_searches;
  Timer timer;  

  void InitLocalSearches();
  StrategyPms* GetStrategy(const std::string& algorithm);
  LocalSearch* GetLocalSearch(const std::string& local_search);
  StopCondition* GetStopCondition(const std::string& stop_condition, size_t iterations);
};

#endif
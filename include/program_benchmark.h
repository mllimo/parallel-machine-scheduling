#ifndef PROGRAM_BENCHMARK_H
#define PROGRAM_BENCHMARK_H

#include <grasp_pms.h>
#include <greedy_pms.h>
#include <gvns.h>
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
#include <vnd.h>

#include <map>
#include <string>
#include <vector>

class ProgramBenchmark : public Program {
 public:
  using Program::Program;
  ~ProgramBenchmark();

  int Run();
  void ShowUsage() const;

 protected:
  std::vector<std::string> header;
  std::vector<std::vector<std::string>> data;

  StrategyPms* algorithm;
  LocalSearch* local_seach;
  StopCondition* stop_condition;
  Gvns* gvns;
  Vnd* vnd;
  std::vector<LocalSearch*> local_searches;
  Timer timer;

  void InitLocalSearches();
  LocalSearch* GetLocalSearch(const std::string& local_search);
  StopCondition* GetStopCondition(const std::string& stop_condition, size_t iterations);

  void Export();
};

#endif
#ifndef PROBLEM_PMS_H
#define PROBLEM_PMS_H

#include <strategy_pms.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>

class ProblemPms {
 public:
  ProblemPms(const std::string& file_path, StrategyPms* strategy);
  ~ProblemPms();

  void Solve();

  friend std::istream& operator>>(std::istream& is, ProblemPms& pms);

 protected:
  size_t machines_;
  std::vector<std::vector<int>> setup_times_;
  std::vector<int> process_times_;
  StrategyPms* algorithm_;
};

#endif
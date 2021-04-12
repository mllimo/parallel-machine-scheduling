#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <set>

class Machine {
 public:
  bool Insert(int process);
  bool Find(int process) const;
  size_t TotalTime() const;
  const std::set<int>& Processes() const;

 private:
  std::set<int> processes_;
  size_t total_time_;
};

#endif
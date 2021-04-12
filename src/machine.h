#include <machine.h>

bool Machine::Insert(int process) {
  return processes_.insert(process).second;
}

bool Machine::Find(int process) const {
  return processes_.find(process) != processes_.end();
}

size_t Machine::TotalTime() const {
  return total_time_;
}

const std::set<int>& Machine::Processes() const {
  return processes_;
}
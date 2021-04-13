#include <machine.h>

Machine::Machine() { total_time_ = 0; }

Machine::Machine(std::vector<int>* jobs_times,
                 std::vector<std::vector<int>>* setup_times) {
  jobs_times_ = jobs_times;
  setup_times_ = setup_times;
  total_time_ = 0;
  last_inserted_ = -1;
}

bool Machine::Insert(int jobs_index) {
  jobs_.push_back(jobs_index);
  last_inserted_ = jobs_index;
  if (jobs_.size() > 1) {
    total_time_ += setup_times_->at(jobs_[jobs_.size() - 2]).at(jobs_.back());
    total_time_ += jobs_times_->at(jobs_.back());
  } else
    total_time_ += jobs_times_->at(jobs_.back());

  return true;
}

bool Machine::Find(int jobs_index) const {
  return std::find(jobs_.begin(), jobs_.end(), jobs_index) != jobs_.end();
}

size_t Machine::TotalTime() const { return total_time_; }

const std::vector<int>& Machine::Jobs() const { return jobs_; }

int Machine::LastInserted() const { return last_inserted_; }

std::ostream& operator<<(std::ostream& os, const Machine& machine) {
  return os;
}
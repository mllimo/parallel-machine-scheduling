#include <machine.h>

Machine::Machine() { 
  total_time_ = 0;
  last_inserted_ = -1;
}

Machine::Machine(std::vector<int>* jobs_times,
                 std::vector<std::vector<int>>* setup_times) {
  jobs_times_ = jobs_times;
  setup_times_ = setup_times;
  total_time_ = 0;
  last_inserted_ = -1;
}

bool Machine::Insert(int jobs_index) {
  jobs_.push_back(jobs_index);

  if (jobs_.size() > 1)
    total_time_ +=
        setup_times_->at(0).at(jobs_index + 1) + jobs_times_->at(jobs_index);
  else
    total_time_ += setup_times_->at(last_inserted_ + 1).at(jobs_index + 1) +
                   jobs_times_->at(jobs_index);

  last_inserted_ = jobs_index;
  return true;
}

bool Machine::Find(int jobs_index) const {
  return std::find(jobs_.begin(), jobs_.end(), jobs_index) != jobs_.end();
}

size_t Machine::TotalTime() const { return total_time_; }

size_t Machine::TctWithJob(int job) const {
  return TCT() + ((jobs_.size() + 1) *
                  (setup_times_->at(last_inserted_ + 1).at(job + 1) +
                   jobs_times_->at(job)));
}

size_t Machine::TCT() const {
  size_t tct = 0;
  for (size_t i = 0; i < jobs_.size(); ++i) {
    if (i > 1)
      tct += (jobs_.size() - i) *
             (setup_times_->at(i + 1).at(i + 1) + jobs_times_->at(jobs_[i]));
    else
      tct += (jobs_.size() - i) *
             (setup_times_->at(0).at(i + 1) + jobs_times_->at(jobs_[i]));
  }
  return tct;
}

const std::vector<int>& Machine::Jobs() const { return jobs_; }

size_t Machine::LastInserted() const { return last_inserted_; }

std::ostream& operator<<(std::ostream& os, const Machine& machine) {
  os << "Procesos: [ ";
  for (auto& job : machine.jobs_) os << job + 1 << " ";
  os << "]";
  return os;
}

bool operator<(const Machine& machine1, const Machine& machine2) {
  return machine1.TCT() < machine2.TCT();
}
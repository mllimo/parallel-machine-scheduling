#include <machine.h>

Machine::Machine() { last_inserted_ = -1; }

Machine::Machine(std::vector<int>* jobs_times, std::vector<std::vector<int>>* setup_times) {
  jobs_times_ = jobs_times;
  setup_times_ = setup_times;
  last_inserted_ = -1;
}

Machine::Machine(const Machine& machine) { *this = machine; }

void Machine::Insert(size_t jobs_index) {
  jobs_.push_back(jobs_index);
  last_inserted_ = jobs_index;
}

void Machine::Insert(size_t index, size_t job_index) {
  jobs_.insert(jobs_.begin() + index, job_index);
}

void Machine::SwapIndexes(size_t i, size_t j) { std::swap(jobs_[i], jobs_[j]); }

bool Machine::Find(size_t job_index) const {
  return std::find(jobs_.begin(), jobs_.end(), job_index) != jobs_.end();
}

size_t Machine::TctWithJob(size_t job) const {
  return TCT() + ((jobs_.size() + 1) *
                  (setup_times_->at(last_inserted_ + 1).at(job + 1) + jobs_times_->at(job)));
}

size_t Machine::TCT() const {
  size_t tct = 0;
  if (jobs_.size() == 0) return std::numeric_limits<size_t>::max();

  for (size_t i = 0; i < jobs_.size(); ++i) {
    if (i > 1)
      tct += (jobs_.size() - i) * (setup_times_->at(i + 1).at(i + 1) + jobs_times_->at(jobs_[i]));
    else
      tct += (jobs_.size() - i) * (setup_times_->at(0).at(i + 1) + jobs_times_->at(jobs_[i]));
  }
  return tct;
}

const std::vector<int>& Machine::Jobs() const { return jobs_; }

std::vector<int>& Machine::Jobs() { return jobs_; }

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

bool operator==(const Machine& machine1, const Machine& machine2) {
  return machine1.jobs_ == machine2.jobs_;
}

Machine& Machine::operator=(const Machine& machine) {
  last_inserted_ = machine.last_inserted_;
  jobs_ = machine.jobs_;
  jobs_times_ = machine.jobs_times_;
  setup_times_ = machine.setup_times_;
  return *this;
}

bool operator<(const std::vector<Machine>& machine1, const std::vector<Machine>& machine2) {
  size_t tct_machine1 = 0;
  size_t tct_machine2 = 0;
  for (const auto& machine : machine1) {
    tct_machine1 += machine.TCT();
  }

  for (const auto& machine : machine2) {
    tct_machine2 += machine.TCT();
  }

  return tct_machine1 < tct_machine2;
}

bool operator==(const std::vector<Machine>& machine1, const std::vector<Machine>& machine2) {
  size_t tct_machine1 = 0;
  size_t tct_machine2 = 0;
  for (const auto& machine : machine1) {
    tct_machine1 += machine.TCT();
  }

  for (const auto& machine : machine2) {
    tct_machine2 += machine.TCT();
  }

  return tct_machine1 == tct_machine2;
}
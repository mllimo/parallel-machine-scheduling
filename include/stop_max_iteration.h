#ifndef STOP_MAX_ITERATION_H
#define STOP_MAX_ITERATION_H

#include <stop_condition.h>
#include <grasp_pms.h>

class StopMaxIteration : public StopCondition {
 public:
  StopMaxIteration(size_t max_iterations);
  ~StopMaxIteration();
  bool operator()(GraspPms* context);

 private:
  size_t max_iterations_;
  size_t current_iterations_;
};

#endif
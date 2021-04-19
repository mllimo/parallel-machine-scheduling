#ifndef STOP_NO_IMPROVEMENT_H
#define STOP_NO_IMPROVEMENT_H

#include <grasp_pms.h>
#include <stop_condition.h>

class StopNoImprovement : public StopCondition {
 public:
  StopNoImprovement(size_t max_iteration_no_improvement);
  ~StopNoImprovement();
  bool operator()(GraspPms* context);

 private:
  size_t max_iteration_no_improvement_;
  size_t iterations_no_improvement_;
};

#endif
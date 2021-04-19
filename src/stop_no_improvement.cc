#include <stop_no_improvement.h>

StopNoImprovement::StopNoImprovement(size_t max_iteration_no_improvement) {
  max_iteration_no_improvement_ = max_iteration_no_improvement;
  iterations_no_improvement_ = 0;
}

StopNoImprovement::~StopNoImprovement() {}

bool StopNoImprovement::operator()(GraspPms* context) {
  if (context->actual_solution < context->best_solution) {
    context->best_solution = context->actual_solution;
    iterations_no_improvement_ = 0;
  } else if (context->actual_solution == context->best_solution) {
    ++iterations_no_improvement_;
  }
  return iterations_no_improvement_ < max_iteration_no_improvement_;
}

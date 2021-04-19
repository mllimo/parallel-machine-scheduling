#include <stop_max_iteration.h>

StopMaxIteration::StopMaxIteration(size_t max_iterations) : StopCondition() {
  max_iterations_ = max_iterations;
  current_iterations_ = 0;
}

StopMaxIteration::~StopMaxIteration() {}

bool StopMaxIteration::operator()(GraspPms* context) {
  if (context->actual_solution < context->best_solution) {
    context->best_solution = context->actual_solution;
  }
  return current_iterations_++ < max_iterations_;
}
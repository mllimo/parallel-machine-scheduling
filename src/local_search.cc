#include <local_search.h>

LocalSearch::~LocalSearch() {}

void LocalSearch::UpdateSolution(std::vector<Machine>& best_solution,
                                 std::vector<Machine>& solution) {
  if (solution < best_solution) {
    best_solution = solution;
  }
}
#include <swap_entre.h>

SwapEntre::~SwapEntre() {}

void SwapEntre::operator()(std::vector<Machine>& solution) {
  auto neighbour_solution = solution;
  // Padre
  for (size_t i = 0; i < neighbour_solution.size(); ++i) {
    // Hijo
    for (size_t j = i + 1; j < neighbour_solution.size(); ++j) {
      // index padre
      for (size_t k = 0; k < neighbour_solution[i].Jobs().size(); ++k) {
        // index hijo
        for (size_t t = 0; t < neighbour_solution[j].Jobs().size(); ++t) {
          std::swap(neighbour_solution[i].Jobs()[k], neighbour_solution[j].Jobs()[t]);
          UpdateSolution(solution, neighbour_solution);
          std::swap(neighbour_solution[i].Jobs()[k], neighbour_solution[j].Jobs()[t]);
        }
      }
    }
  }
}

void SwapEntre::operator()(std::vector<Machine>& solution, size_t k) {
  size_t steps = 0;
  for (size_t i = 0; i < solution.size(); ++i) {
    for (size_t j = i + 1; j < solution.size(); ++j) {
      for (size_t k = 0; k < solution[i].Jobs().size(); ++k) {
        for (size_t t = 0; t < solution[j].Jobs().size(); ++t) {
          steps += 1;
          if (steps == k) {
            std::swap(solution[i].Jobs()[k], solution[j].Jobs()[t]);
            return;
          }
        }
      }
    }
  }
}
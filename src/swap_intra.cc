#include <swap_intra.h>

SwapIntra::~SwapIntra() {}

void SwapIntra::operator()(std::vector<Machine>& solution) {
  auto neighbour_solution = solution;
  for (size_t i = 0; i < neighbour_solution.size(); ++i) {
    for (size_t j = 0; j < neighbour_solution[i].Jobs().size(); ++j) {
      for (size_t k = j + 1; k < neighbour_solution[i].Jobs().size(); ++k) {
        neighbour_solution[i].SwapIndexes(j, k);
        UpdateSolution(solution, neighbour_solution);
        neighbour_solution[i].SwapIndexes(j, k);
      }
    }
  }
}

void SwapIntra::operator()(std::vector<Machine>& solution, size_t k) {
  size_t steps = 0;
  for (size_t i = 0; i < solution.size(); ++i) {
    for (size_t j = 0; j < solution[i].Jobs().size(); ++j) {
      for (size_t k = j + 1; k < solution[i].Jobs().size(); ++k) {
        steps += 1;
        if (steps == k) {
          solution[i].SwapIndexes(j, k);
          return;
        }
      }
    }
  }
}
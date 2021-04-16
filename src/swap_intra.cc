#include <swap_intra.h>

SwapIntra::~SwapIntra() {}

void SwapIntra::operator()(std::vector<Machine>& solution) {
  auto best_neighbour_solution = solution;
  auto neighbour_solution = solution;
  for (size_t i = 0; i < neighbour_solution.size(); ++i) {
    for (size_t j = 0; j < neighbour_solution[i].Jobs().size(); ++j) {
      for (size_t k = j + 1; k < neighbour_solution[i].Jobs().size(); ++k) {
        std::swap(neighbour_solution[i].Jobs()[j], neighbour_solution[i].Jobs()[k]);
        UpdateSolution(best_neighbour_solution, neighbour_solution);
        neighbour_solution = solution;
      }
    }
  }
  solution = best_neighbour_solution;
}
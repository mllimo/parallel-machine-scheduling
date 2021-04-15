#include <swap_intra.h>

SwapIntra::~SwapIntra() {}

void SwapIntra::operator()(std::vector<Machine>& solution) {
  auto best_neighbour_solution = solution;
  auto neighbour_solution = solution;
  // Padre
  for (size_t i = 0; i < neighbour_solution.size(); ++i) {
    // Hijo
    for (size_t j = i + 1; j < neighbour_solution.size(); ++j) {
      // index padre
      for (size_t k = 0; k < neighbour_solution[i].Jobs().size(); ++k) {
        // index hijo
        for (size_t t = 0; t < neighbour_solution[j].Jobs().size(); ++t) {
          std::swap(neighbour_solution[i].Jobs()[k],
                    neighbour_solution[j].Jobs()[t]);
        }
        // Ver si mejor | Compararlos con todos lo vecinos | Con el primer en
        // mejorar
        if (neighbour_solution < best_neighbour_solution) {
          best_neighbour_solution = neighbour_solution;
        }
        // reset
        neighbour_solution = solution;
      }
    }
  }
  solution = best_neighbour_solution;
}
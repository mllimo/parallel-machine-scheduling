#include <reinsert_intra.h>

ReinsertIntra::~ReinsertIntra() {}

void ReinsertIntra::operator()(std::vector<Machine>& solution) {
  auto best_neighbour_solution = solution;
  auto neighbour_solution = solution;
  size_t erase_element;
  // maquinas
  for (size_t i = 0; i < neighbour_solution.size(); ++i) {
    for (size_t erase = 0; erase < neighbour_solution[i].Jobs().size() - 1; ++erase) {
      for (size_t insert = erase + 1; insert < neighbour_solution[i].Jobs().size() - 1; ++insert) {
        erase_element = neighbour_solution[i].Jobs()[erase];
        neighbour_solution[i].Jobs().erase(neighbour_solution[i].Jobs().begin() + erase);
        neighbour_solution[i].Jobs().insert(neighbour_solution[i].Jobs().begin() + insert, erase_element);
        // Poco eficiente,. intentar refactorizar
        if (neighbour_solution < best_neighbour_solution) {
          best_neighbour_solution = neighbour_solution;
        }
        neighbour_solution = solution;
      }
    }
  }
  solution = best_neighbour_solution;
}
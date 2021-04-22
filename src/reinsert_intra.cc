#include <reinsert_intra.h>

ReinsertIntra::~ReinsertIntra() {}

void ReinsertIntra::operator()(std::vector<Machine>& solution) {
  auto neighbour_solution = solution;
  size_t erase_element;
  // maquinas
  for (size_t i = 0; i < neighbour_solution.size(); ++i) {
    for (size_t erase = 0; erase < neighbour_solution[i].Jobs().size() - 1; ++erase) {
      for (size_t insert = erase + 1; insert <= neighbour_solution[i].Jobs().size(); ++insert) {
        erase_element = neighbour_solution[i].Jobs()[erase];
        neighbour_solution[i].Jobs().erase(neighbour_solution[i].Jobs().begin() + erase);

        if (insert < neighbour_solution[i].Jobs().size())
          neighbour_solution[i].Insert(insert, erase_element);
        else
          neighbour_solution[i].Insert(erase_element);

        UpdateSolution(solution, neighbour_solution);
        neighbour_solution = solution;
      }
    }
  }
}
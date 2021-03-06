#include <reinsert_entre.h>

ReinsertEntre::~ReinsertEntre() {}

void ReinsertEntre::operator()(std::vector<Machine>& solution) {
  auto neighbour_solution = solution;
  size_t erase_element;
  for (size_t i = 0; i < neighbour_solution.size(); ++i) {
    for (size_t j = 0; j < neighbour_solution.size() && i != j; ++j) {
      for (size_t k = 0; k < neighbour_solution[i].Jobs().size(); ++k) {
        for (size_t t = 0; t <= neighbour_solution[j].Jobs().size(); ++t) {
          erase_element = neighbour_solution[i].Jobs()[k];
          neighbour_solution[i].Jobs().erase(neighbour_solution[i].Jobs().begin() + k);

          if (t < neighbour_solution[j].Jobs().size())
            neighbour_solution[j].Insert(t, erase_element);
          else
            neighbour_solution[j].Insert(erase_element);

          UpdateSolution(solution, neighbour_solution);
          neighbour_solution = solution;
        }
      }
    }
  }
}

void ReinsertEntre::operator()(std::vector<Machine>& solution, size_t k) {
  size_t erase_element;
  size_t steps = 0;
  for (size_t i = 0; i < solution.size(); ++i) {
    for (size_t j = 0; j < solution.size() && i != j; ++j) {
      for (size_t k = 0; k < solution[i].Jobs().size(); ++k) {
        for (size_t t = 0; t <= solution[j].Jobs().size(); ++t) {
          steps += 1;
          if (steps == k) {
            erase_element = solution[i].Jobs()[k];
            solution[i].Jobs().erase(solution[i].Jobs().begin() + k);

            if (t < solution[j].Jobs().size())
              solution[j].Insert(t, erase_element);
            else
              solution[j].Insert(erase_element);
            return;
          }
        }
      }
    }
  }
}
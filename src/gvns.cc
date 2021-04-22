#include <gvns.h>

Gvns::Gvns(size_t k, LocalSearch* local, Vnd* vnd_) : Vns(k), local_search(local), vnd(vnd_) {}

Gvns::~Gvns() { delete vnd; }

void Gvns::operator()(std::vector<Machine>& solution) {
  std::vector<Machine> partial_solution = solution;
  size_t k;
  do {
    k = 1;
    while (k < k_neighborhood) {
      Shake(k, partial_solution);
      (*vnd)(partial_solution);
      if (partial_solution < solution){
        solution = partial_solution;
        k = 1;
      } else {
        partial_solution = solution;
        k += 1;
      }
    }
  } while (partial_solution != solution);
}

void Gvns::Shake(size_t k, std::vector<Machine>& partial_solution) {
  (*local_search)(partial_solution, k);
}
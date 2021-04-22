#include <vnd.h>

Vnd::Vnd(const std::vector<LocalSearch*>& local) : local_searches(local) {}

Vnd::~Vnd() {}

void Vnd::operator()(std::vector<Machine>& solution) {
  size_t index = 0;
  std::vector<Machine> aux =  solution;
  while (index < local_searches.size()) {
    (*local_searches[index])(aux);
    if (aux < solution) {
      solution = aux;
      index = 1;
    } else {
      aux = solution;
      index += 1;
    }
  }
}
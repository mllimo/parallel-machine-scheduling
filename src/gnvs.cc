#include <gnvs.h>

Gnvs::Gnvs(size_t k, LocalSearch* local) : Vns(k), local_search(local) {}

Gnvs::~Gnvs() {}

void Gnvs::operator()(std::vector<Machine>& solution) {
  
}

std::vector<Machine> Gnvs::Shake(size_t k) {}
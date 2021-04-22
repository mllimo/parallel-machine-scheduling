#ifndef GVNS_H
#define GVNS_H

#include <vns.h>
#include <vnd.h>

class Gvns : public Vns {
 public:
  Gvns(size_t k, LocalSearch* local, Vnd* vnd_);
  ~Gvns();

  void operator()(std::vector<Machine>& solution);

 protected:
  LocalSearch* local_search;
  Vnd* vnd;
  void Shake(size_t k, std::vector<Machine>& partial_solution);
};

#endif
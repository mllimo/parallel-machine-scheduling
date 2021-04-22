#ifndef GNVS_H
#define GNVS_H

#include <vns.h>

class Gnvs : public Vns {
 public:
  Gnvs(size_t k, LocalSearch* local);
  ~Gnvs();

  void operator()(std::vector<Machine>& solution);

 protected:
  LocalSearch* local_search;

  std::vector<Machine> Shake(size_t k);
};

#endif
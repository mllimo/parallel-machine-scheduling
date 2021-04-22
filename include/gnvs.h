#ifndef GNVS_H
#define GNVS_H

#include <vns.h>
#include <vnd.h>

class Gnvs : public Vns {
 public:
  Gnvs(size_t k, LocalSearch* local, Vnd* vnd_);
  ~Gnvs();

  void operator()(std::vector<Machine>& solution);

 protected:
  LocalSearch* local_search;
  Vnd* vnd;
  void Shake(size_t k, std::vector<Machine>& partial_solution);
};

#endif
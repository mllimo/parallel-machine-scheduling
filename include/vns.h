#ifndef VNS_H
#define VNS_H

#include <vector>
#include <machine.h>
#include <local_search.h>

class Vns {
 public:
  Vns(size_t k);
  virtual ~Vns();

  virtual void operator()(std::vector<Machine>& solution) = 0;

 protected:
  size_t k_neighborhood;
};

#endif
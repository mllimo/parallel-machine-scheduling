#ifndef VND_H
#define VND_H

#include <machine.h>
#include <local_search.h>

#include <vector>

class Vnd {
 public:
  Vnd(const std::vector<LocalSearch*>& local);
  ~Vnd();

  void operator()(std::vector<Machine>& solution);

 protected:
  std::vector<LocalSearch*> local_searches;
};

#endif
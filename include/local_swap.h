#ifndef LOCAL_SWAP_H
#define LOCAL_SWAP_H

#include <local_search.h>

class LocalSwap : public LocalSearch {
 public:
  virtual ~LocalSwap();
  virtual void operator()(std::vector<Machine>& solution) = 0;
  virtual void operator()(std::vector<Machine>& solution, size_t k) = 0;
};

#endif
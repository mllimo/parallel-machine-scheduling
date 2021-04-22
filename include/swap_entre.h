#ifndef SWAP_ENTRE_H
#define SWAP_ENTRE_H

#include <local_swap.h>

class SwapEntre : public LocalSwap {
 public:
  ~SwapEntre();
  void operator()(std::vector<Machine>& solution);
  void operator()(std::vector<Machine>& solution, size_t k);
};

#endif
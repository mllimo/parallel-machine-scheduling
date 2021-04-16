#ifndef SWAP_ENTRA_H
#define SWAP_ENTRA_H

#include <local_swap.h>

class SwapEntra : public LocalSwap {
 public:
  ~SwapEntra();
  void operator()(std::vector<Machine>& solution);
};

#endif
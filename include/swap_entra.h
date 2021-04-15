#ifndef SWAP_INTRA_H
#define SWAP_INTRA_H

#include <local_swap.h>

class SwapEntra : public LocalSwap {
 public:
  ~SwapEntra();
  void operator()(std::vector<Machine>& solution);
};

#endif
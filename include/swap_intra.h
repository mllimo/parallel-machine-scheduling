#ifndef SWAP_INTRA_H
#define SWAP_INTRA_H

#include <local_swap.h>

class SwapIntra : public LocalSwap {
  public:
  ~SwapIntra();
  void operator()(std::vector<Machine>& solution);
  void operator()(std::vector<Machine>& solution, size_t k);
};


#endif
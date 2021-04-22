#ifndef REINSERT_INTRA_H
#define REINSERT_INTRA_H

#include <local_reinsert.h>

class ReinsertIntra : public LocalReinsert {
  public:
    ~ReinsertIntra();
    void operator()(std::vector<Machine>& solution);
    void operator()(std::vector<Machine>& solution, size_t k);
};

#endif
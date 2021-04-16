#ifndef LOCAL_REINSERT_H
#define LOCAL_REINSERT_H

#include <local_search.h>

class LocalReinsert : public LocalSearch {
  public:
    virtual ~LocalReinsert();
    virtual void operator()(std::vector<Machine>& solution) = 0;
};


#endif
#ifndef LOCAL_SEARCH_H
#define LOCAL_SEARCH_H

#include <machine.h>

class LocalSearch {
public:
  virtual ~LocalSearch();
  virtual void operator()(std::vector<Machine>& solution) = 0;
};

#endif
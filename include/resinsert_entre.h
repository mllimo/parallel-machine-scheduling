#ifndef RESINSERT_ENTRE_H
#define RESINSERT_ENTRE_H

#include <local_reinsert.h>

class ReinsertEntre : public LocalReinsert {
 public:
  ~ReinsertEntre();
  void operator()(std::vector<Machine>& solution);
};

#endif
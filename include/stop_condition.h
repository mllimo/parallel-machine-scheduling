#ifndef STOP_CONDITION_H
#define STOP_CONDITION_H

#include <iostream>
class GraspPms;

class StopCondition {
 public:
  virtual ~StopCondition();
  virtual bool operator()(GraspPms* context) = 0;
};

#endif
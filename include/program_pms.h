#ifndef PROGRAM_PMS_H
#define PROGRAM_PMS_H

#include <problem_pms.h>
#include <greedy_pms.h>
#include <program.h>

class ProgramPms : public Program {
 public:
  using Program::Program;
  ~ProgramPms();

  int Run();
  void ShowUsage() const;
};

#endif
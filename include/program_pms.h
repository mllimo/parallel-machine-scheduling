#ifndef PROGRAM_PMS_H
#define PROGRAM_PMS_H

#include <grasp_pms.h>
#include <greedy_pms.h>
#include <my_greedy_pms.h>
#include <problem_pms.h>
#include <program.h>
#include <reinsert_entre.h>
#include <reinsert_intra.h>
#include <swap_entre.h>
#include <swap_intra.h>
#include <stop_no_improvement.h>
#include <stop_max_iteration.h>

class ProgramPms : public Program {
 public:
  using Program::Program;
  ~ProgramPms();

  int Run();
  void ShowUsage() const;
};

#endif
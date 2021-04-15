#include <program_pms.h>

ProgramPms::~ProgramPms() {}

int ProgramPms::Run() {
  ProblemPms problem(arg_[1], new GreedyPms());
  problem.Solve();
  std::cout << problem << std::endl;

  ProblemPms problem2(arg_[1], new MyGreedyPms());
  problem2.Solve();
  std::cout << problem2 << std::endl;

  ProblemPms problem3(arg_[1], new GraspPms(3, 5, new SwapEntra()));
  problem3.Solve();
  std::cout << problem3 << std::endl;
  return 0;
}

void ProgramPms::ShowUsage() const {
  std::cout << "Way of use: ./pms <data-file-path>\n";
}
#include <program_pms.h>

ProgramPms::~ProgramPms() {

}

int ProgramPms::Run() {
  ProblemPms problem(arg_[1], new GreedyPms());
  problem.Solve();
  std::cout << problem << std::endl;

  ProblemPms problem2(arg_[1], new MyGreedyPms());
  problem2.Solve();
  std::cout << problem2 << std::endl;
  return 0;
}

void ProgramPms::ShowUsage() const {
  std::cout << "Way of use: ./pms <data-file-path>\n";
}
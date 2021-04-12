#include <program_pms.h>

ProgramPms::~ProgramPms() {

}

int ProgramPms::Run() {
  ProblemPms problem(arg_[1], new GreedyPms());
  return 0;
}

void ProgramPms::ShowUsage() const {
  std::cout << "Way of use: ./pms <data-file-path>\n";
}
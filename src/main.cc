#include <program_benchmark.h>
#include <program_pms.h>

void ShowUsage();

int main(int argc, char const* argv[]) {
  Program* program = NULL;
  int return_value = -1;
  if (argc == 1) {
    ShowUsage();
    return -1;
  } else if (std::string(argv[1]) == "-t") {
    program = new ProgramBenchmark(argc, argv);
  } else {
    program = new ProgramPms(argc, argv);
  }
  return_value = program->Run();
  delete program;
  return return_value;
}

void ShowUsage() {
  Program* program = NULL;
  program = new ProgramPms({""});
  program->Run();
  delete program;
  program = new ProgramBenchmark({""});
  program->Run();
  delete program;
}

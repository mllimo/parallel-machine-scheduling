#include <program.h>

Program::Program(int argc, char const *argv[]) { arg_ = ParseArgv(argc, argv); }

Program::~Program() {}

std::vector<std::string> Program::ParseArgv(int argc, char const *argv[]) {
  std::vector<std::string> arguments;
  arguments.insert(arguments.end(), argv, argv + argc);
  return arguments;
}
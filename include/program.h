#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Program {
 public:
  Program(const std::vector<std::string>& argv);
  Program(int argc, char const *argv[]);
  virtual ~Program();

  virtual int Run() = 0;
  virtual void ShowUsage() const = 0;

 protected: 
  std::vector<std::string> arg_;

 protected:
  std::vector<std::string> ParseArgv(int argc, char const *argv[]);
};

#endif
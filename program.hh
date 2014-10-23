#ifndef HACK_PROGRAM_H_ 
#define HACK_PROGRAM_H_

#include <string>
#include <vector>
#include "instruction.hh"

namespace hack {

class Program {
  public:
    Program(std::string);
    std::string asHackBinary();
    std::string asNormalizedAssembly();
    std::vector<hack::Instruction*> asInstructions();

  private:
    std::string assemblySource;
    std::string normalizeAssembly(std::string);
    std::string stripWhitespace(std::string);
    std::string stripComments(std::string);
};

class InvalidSyntaxException {
  public:
    InvalidSyntaxException(std::string message="Invalid Syntax");
    std::string what() throw();

  private:
    std::string message;
};


}
#endif // HACK_PROGRAM_H_



#include "ainstruction.hh"
#include <string>
#include "program.hh"

namespace hack {

AInstruction::AInstruction(Program *parentProgram, std::string source) {
    this->program = parentProgram;
    this->assembly = source;
}

std::string AInstruction::asAssembly() {
    return assembly;
}

std::string AInstruction::asHackBinary() {
  return "unimplemented";
}

}


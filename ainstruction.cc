
#include "ainstruction.hh"
#include <string>
#include "program.hh"

namespace hack {

AInstruction::AInstruction(Program program, std::string assembly) {
}

std::string AInstruction::asAssembly() {
  return "unimplemented";
}

std::string AInstruction::asHackBinary() {
  return "unimplemented";
}

}


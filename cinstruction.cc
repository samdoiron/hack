
#include "cinstruction.hh"
#include <string>
#include "invalidsyntaxexception.hh"

namespace hack {

CInstruction::CInstruction(std::string) {
}

std::string CInstruction::asAssembly() {
  return "unimplemented";
}

std::string CInstruction::asHackBinary() {
  return "unimplemented";
}

}




#include "dinstruction.hh"
#include <string>
#include "invalidsyntaxexception.hh"

namespace hack {

DInstruction::DInstruction(std::string) {
}

std::string DInstruction::asAssembly() {
  return "unimplemented";
}

std::string DInstruction::asHackBinary() {
  return "unimplemented";
}

}



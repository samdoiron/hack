
#include <string>
#include "instruction.hh"

namespace hack {

class AInstruction : Instruction {
  public:
    std::string asHackBinary();
    std::string asAssembly();
};

}


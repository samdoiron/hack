
#include <string>
#include "instruction.hh"
#include "program.hh"

namespace hack {

class AInstruction : public Instruction {
  public:
    AInstruction(Program*, std::string);
    std::string asHackBinary();
    std::string asAssembly();
};

}


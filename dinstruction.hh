#ifndef HACK_DINSTRUCTION_H_
#define HACK_DINSTRUCTION_H_

#include <string>
#include "instruction.hh"

namespace hack {

class DInstruction : Instruction {
  public:
    std::string asAssembly();
    std::string asHackBinary();
};

}

#endif // HACK_DINSTRUCTION_H


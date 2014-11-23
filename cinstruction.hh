#ifndef HACK_CINSTRUCTION_H_
#define HACK_CINSTRUCTION_H_

#include <string>
#include "instruction.hh"

namespace hack {

class CInstruction : public Instruction {
  public:
    CInstruction(std::string);
    std::string asHackBinary();
    std::string asAssembly();
};

}

#endif // HACK_CINSTRUCTION_H


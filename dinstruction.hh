#ifndef HACK_DINSTRUCTION_H_
#define HACK_DINSTRUCTION_H_

#include <string>
#include "instruction.hh"

namespace hack {

class DInstruction : public Instruction {
  public:
    DInstruction(std::string);
    std::string asHackBinary();
    std::string asAssembly();
};

}

#endif // HACK_DINSTRUCTION_H


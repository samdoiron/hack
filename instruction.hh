

#ifndef HACK_INSTRUCTION_H_
#define HACK_INSTRUCTION_H_

#include <string>

namespace hack {

class Instruction {
  public:
    virtual ~Instruction() {}
    virtual std::string asAssembly() = 0;
    virtual std::string asHackBinary() = 0;
  
    static Instruction* fromAssembly(std::string);
};

}

#endif // HACK_INSTRUCTION_H_




#ifndef HACK_INSTRUCTION_H_
#define HACK_INSTRUCTION_H_

namespace hack {

class Instruction {
  public:
    virtual ~Instruction() {}
    virtual void asAssembly() = 0;
    virtual void asHackBinary() = 0;
  
    static Instruction* fromAssembly(std::string);
};

}

#endif // HACK_INSTRUCTION_H_


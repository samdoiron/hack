

#ifndef HACK_INSTRUCTION_H_
#define HACK_INSTRUCTION_H_

#include <string>
#include "program.hh"


namespace hack {

class Program;

class Instruction {
    public:
        virtual ~Instruction() {}
        virtual std::string asAssembly() = 0;
        virtual std::string asHackBinary() = 0;

        static Instruction* fromAssembly(Program*, std::string);

    private:
        virtual void anchor();
};

}

#endif // HACK_INSTRUCTION_H_


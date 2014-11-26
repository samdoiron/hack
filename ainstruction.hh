
#include <string>
#include "instruction.hh"
#include "program.hh"

namespace hack {

class AInstruction : public Instruction {
    public:
        AInstruction(Program*, std::string);
        std::string asHackBinary();
        std::string asAssembly();
    private:
        Program *program;
        std::string assembly;
        std::string binary;
        std::string getBinary();
        int getValue();
        bool isLiteral();
        bool isVariable();
};

}


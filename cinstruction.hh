#ifndef HACK_CINSTRUCTION_H_
#define HACK_CINSTRUCTION_H_

#include <string>
#include "instruction.hh"
#include "invalidsyntaxexception.hh"

#include  <boost/regex.hpp>

namespace hack {

class CInstruction : public Instruction {
    public:
        CInstruction(std::string);
        std::string asHackBinary();
        std::string asAssembly();
    private:
        std::string assembly, binary;
        std::string getBinary();
        std::string getHeaderBinary();
        std::string getDestBinary();
        std::string getJumpBinary();
        std::string getOperationBinary();

        std::string getDest();
        std::string getOperation();
        std::string getJump();

        std::string findMatch(boost::regex, std::string);

        bool hasDest();
        bool isMemoryOperation();
        InvalidSyntaxException invalidException(std::string, std::string);
};

}

#endif // HACK_CINSTRUCTION_H


#include <string>
#include <sstream>
#include <bitset>
#include <climits>

#include <boost/regex.hpp>

#include "ainstruction.hh"
#include "program.hh"
#include "invalidsyntaxexception.hh"

namespace hack {

AInstruction::AInstruction(Program *parentProgram, std::string inputAssembly) {
    this->program = parentProgram;
    this->assembly = inputAssembly;
    this->binary = this->getBinary();
}

std::string AInstruction::asAssembly() {
    return assembly;
}

std::string AInstruction::asHackBinary() {
    return this->binary;
}

// --- private

std::string AInstruction::getBinary() {
    std::ostringstream binaryStream;
    // Convert the value into a binary string, and prepend "0"

    binaryStream << "0" << std::bitset<15>((unsigned long long)(this->getValue()));
    return binaryStream.str();
}

bool AInstruction::isLiteral() {
    static const boost::regex literalPattern("@\\d+");
    return boost::regex_match(this->assembly, literalPattern);
}

bool AInstruction::isVariable() {
    static const boost::regex literalPattern("@[a-zA-Z:\\.\\$][\\w:\\.\\$\\d]*");
    return boost::regex_match(this->assembly, literalPattern);
}

int AInstruction::getValue() {
    std::string valueName = this->assembly;
    valueName.erase(0, 1); // Remove leading '@'
    if (this->isLiteral()) {
        try {
            return std::stoi(valueName);
        } catch(std::out_of_range){
            throw InvalidSyntaxException("Literal value is too large");
        }
    } else if (this->isVariable()) {
        // '@someVarName' case
        return program->getVariableValue(valueName);
    } else {
        throw InvalidSyntaxException("Invalid variable name.");
    }
}

}


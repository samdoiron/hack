#include <string>
#include <sstream>
#include <bitset>

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
    binaryStream << "0"
        << std::bitset<15>(this->getValue());
    return binaryStream.str();
}

int AInstruction::getValue() {
    static const boost::regex literalPattern("\\d+");
    std::string valueName = this->assembly;
    valueName.erase(0, 1); // Remove leading '@'

    bool isLiteralValue = boost::regex_match(valueName, literalPattern);
    if (isLiteralValue) {
        return std::stoi(valueName);
    } else {
        return program->getVariableValue(valueName);
    }
}

}


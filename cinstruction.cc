#include <unordered_map>

#include "cinstruction.hh"
#include <string>
#include "invalidsyntaxexception.hh"

#include <boost/regex.hpp>

namespace hack {

std::unordered_map<std::string, std::string> CInstruction::instructionCache;

// CInstructions have the following format:
// [1 1 1 a][c1 c2 c3 c4 c5 c6][d1 d2 d3][j1 j2 j3]
// <header> <    operation    ><  dest  ><  jump  >
//
// And in HACK assembly:
// < dest? >=< operation >;< jump? >
//
// Where 'header' contains the memory access flag 'a'.
//       'operation' defines the calculation to be performed (eg A+D)
//       'dest' defines where the operation is stored (eg 'D')
//       'jump' defines the conditions under which a jump occurs (eg. 'JEQ').
CInstruction::CInstruction(std::string inputAssembly) {
    this->assembly = inputAssembly;
    this->binary = this->getBinary();
}

std::string CInstruction::asAssembly() {
    return this->assembly;
}

std::string CInstruction::asHackBinary() {
    return this->binary;
}

// --- private

// The binary form of a given instruction is statically cached to improve
// performance (in practise, this leads to about ~33% speed up).
void CInstruction::cacheBinary(std::string calculated) {
    instructionCache.insert(std::make_pair(this->assembly, calculated));
}

bool CInstruction::hasCachedBinary() {
    return instructionCache.count(this->assembly) == 1;
}

std::string CInstruction::getCachedBinary() {
    return instructionCache.at(this->assembly);
}

std::string CInstruction::getBinary() {
    if (this->hasCachedBinary()) {
        return this->getCachedBinary();
    }
    std::ostringstream binaryStream;
    binaryStream
        << this->getHeaderBinary()
        << this->getOperationBinary()
        << this->getDestBinary()
        << this->getJumpBinary();
    std::string bin = binaryStream.str();
    this->cacheBinary(bin);
    return bin;
}

bool CInstruction::hasDest() {
    return this->assembly.find("=") != std::string::npos;
}

std::string CInstruction::getDest() {
    static const boost::regex destPattern(".{1,3}=");

    // If there is no destination, the calculation has no '=' (eg. D;JEQ)
    if (this->hasDest()) {
        std::string match = this->findMatch(destPattern, this->assembly);
        match.erase(match.length()-1); // Leave off the trailing '='
        return match;
    } else {
        return "";
    }

}

// Find the operation part of a given instruction.
std::string CInstruction::getOperation() {
    static const boost::regex destOperationPattern("=[^;]{1,3}");
    static const boost::regex noDestOperationPattern("[^;]{1,3}");
    if (this->hasDest()) {
        std::string match = this->findMatch(destOperationPattern, this->assembly);
        match.erase(0, 1); // Remove the leading '='
        return match;
    } else {
        std::string match = this->findMatch(noDestOperationPattern, this->assembly);
        return match;
    }
}

// Find the jump part of the given instruction, or "" if there is none.
std::string CInstruction::getJump() {
    static const boost::regex jumpPattern(";...");
    std::string match = this->findMatch(jumpPattern, this->assembly);
    match.erase(0, 1); // Leave of the leading ';'
    return match;
}

// Return the first substring of haystack that matches needle, or "" if there
// is no match.
std::string CInstruction::findMatch(boost::regex needle, std::string haystack) {
    boost::match_results<std::string::const_iterator> match;
    bool matchFound = boost::regex_search(haystack, match, needle);
    return matchFound ? match.str() : "";
}

std::string CInstruction::getHeaderBinary() {
    return this->isMemoryOperation() ? "1111" : "1110";
}

std::string CInstruction::getDestBinary() {
    std::string dest = this->getDest();
    if (dest == "")    return "000";
    if (dest == "M")   return "001";
    if (dest == "D")   return "010";
    if (dest == "MD")  return "011";
    if (dest == "A")   return "100";
    if (dest == "AM")  return "101";
    if (dest == "AD")  return "110";
    if (dest == "AMD") return "111";
    throw this->invalidException("destination", dest);
}

std::string CInstruction::getOperationBinary() {
    std::string op = this->getOperation();

    // There relationship between the operation and its resulting binary
    // is complicated enough that it is far easier to just use a big if
    // chain like this (as ugly as it is).
    if (op == "!M")  return "110001";
    if (op == "M-1") return "110010";
    if (op == "M+1") return "110111";
    if (op == "D-M") return "010011";
    if (op == "M-D") return "000111";
    if (op == "0")   return "101010";
    if (op == "1")   return "111111";
    if (op == "-1")  return "111010";
    if (op == "D")   return "001100";
    if (op == "M")   return "110000";
    if (op == "A")   return "110000";
    if (op == "!D")  return "001101";
    if (op == "!A")  return "110001";
    if (op == "-D")  return "001111";
    if (op == "-A")  return "110011";
    if (op == "-M")  return "110011";
    if (op == "D+1") return "011111";
    if (op == "A+1") return "110111";
    if (op == "D-1") return "001110";
    if (op == "A-1") return "110010";
    if (op == "D-A") return "010011";
    if (op == "A-D") return "000111";
    // + & and | are orderless
    if (op == "D+M" || op == "M+D") return "000010";
    if (op == "D+A" || op == "A+D") return "000010";
    if (op == "D|M" || op == "M|D") return "010101";
    if (op == "D|A" || op == "A|D") return "010101";
    if (op == "D&M" || op == "M&D") return "000000";
    if (op == "D&A" || op == "A&D") return "000000";
    throw this->invalidException("operation", op);
}

std::string CInstruction::getJumpBinary() {
    std::string jmp = this->getJump();
    if (jmp.empty())  return "000";
    if (jmp == "JGT") return "001";
    if (jmp == "JEQ") return "010";
    if (jmp == "JGE") return "011";
    if (jmp == "JLT") return "100";
    if (jmp == "JNE") return "101";
    if (jmp == "JLE") return "110";
    if (jmp == "JMP") return "111";
    std::ostringstream error;
    throw this->invalidException("jump expression", jmp);
}

bool CInstruction::isMemoryOperation() {
    std::string operation = this->getOperation();
    return operation.find("M") != std::string::npos;
}

InvalidSyntaxException CInstruction::invalidException(std::string type, std::string value) {
    std::ostringstream error;
    error << "Invalid " << type << " \"" << value << "\"";
    return InvalidSyntaxException(error.str());
}

}


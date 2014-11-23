#include "program.hh"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <boost/log/trivial.hpp>

#include "label.hh"
#include "instruction.hh"
#include "invalidsyntaxexception.hh"

namespace hack { 

Program::Program(std::string source) {
    // TODO: Refactor streams to ostream / istream.
    std::string line;
    std::stringstream inputStream(source);
    std::stringstream normalizedStream;
    int lineNumber = 1;

    // Normalize assembly and load labels (on single pass for efficiency)
    while (getline(inputStream, line)) {
        std::string normalizedLine = this->normalizeLine(line);

        BOOST_LOG_TRIVIAL(trace) 
            << "Normalized line " << line << " to " << normalizedLine;

        // Skip empty lines
        if (!normalizedLine.empty()) {
            continue;
        }

        // Load any found labels
        if (Label::isValid(line)) {
            this->addLabel(Label(normalizedLine, lineNumber));
        }

        normalizedStream << line;
    }

    // Second pass, read in all instructions.
    // This must be done after all labels are loaded, because AInstructions 
    // need to know label addresses.
    while (getline(inputStream, line)) {
        try {
            Instruction *lineInstruction = Instruction::fromAssembly(this, line);
            this->addInstruction(lineInstruction);
        } catch (InvalidSyntaxException e) {
            this->reportError(e);
        }
    }
}

std::string Program::asHackBinary() {
    std::stringstream compiledBinary; 

    for (Instruction *instruction : this->instructions) {
        compiledBinary << instruction->asHackBinary() << std::endl;
    }

    return compiledBinary.str();
}

std::string Program::asNormalizedAssembly() {
    std::stringstream compiledBinary; 

    for (Instruction *instruction : this->instructions) {
        compiledBinary << instruction->asAssembly() << std::endl;
    }

    return compiledBinary.str();
}

std::vector<Instruction*> Program::asInstructions() {
    return this->instructions;
}

// --- private

std::string Program::normalizeLine(std::string line) {
    std::string normalized = this->stripComments(line);
    boost::algorithm::trim(normalized);
    return normalized;
}

void Program::reportError(std::runtime_error error) {
    std::cout << error.what() << std::endl;
}

// Program::stripComments() removes all "//" style comments from the given
// std::string.
std::string Program::stripComments(std::string assembly) {
    boost::regex commentRegex(std::string("//.*"));
    return boost::regex_replace(assembly, commentRegex, "");
}

void Program::addInstruction(Instruction *instr) {
    this->instructions.push_back(instr);
}

void Program::addLabel(Label label) {
    this->labels.push_back(label);
}

}


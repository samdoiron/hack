#include "program.hh"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <unordered_map>

#include <boost/regex.hpp>

#include "variable.hh"
#include "instruction.hh"
#include "invalidsyntaxexception.hh"

namespace hack { 

Program::Program(std::string source) {
    // TODO: Refactor streams to ostream / istream.
    std::string line;
    std::stringstream inputStream(source);
    std::stringstream normalizedStream;

    // Variable allocation begins at address 16 (right after @R15)
    this->nextVariableAddress = 16;

    // Load in global constant variables (eg. @KBD)
    this->loadConstants();

    // Record the compiled line number (which does not include empty lines
    // or labels) to determine the value of labels when they are encountered.
    int compiledLineNumber = 0;

    // Normalize assembly and load vars (on single pass for efficiency)
    while (getline(inputStream, line)) {
        std::string normalizedLine = this->normalizeLine(line);

        // Load any found labels
        if (this->lineIsLabel(normalizedLine)) {
            std::string varName = normalizedLine;
            // Remove '(' and ')'
            varName.erase(0, 1);
            varName.erase(varName.length()-1);
            this->addVariable(Variable(varName, compiledLineNumber));
        } else {
            compiledLineNumber += 1;
        }

        normalizedStream << normalizedLine << "\n";
    }

    // Second pass, read in all instructions.
    // This must be done after all vars are loaded, because AInstructions 
    // need to know var addresses.
    // Here we keep track of the source line number, for error messages.
    int sourceLineNumber = 0;
    while (getline(normalizedStream, line)) {
        sourceLineNumber += 1;

        // Skip empty lines
        if (line.empty()) {
            continue;
        }

        // If the line is a var, ignore it.
        if (!this->lineIsLabel(line)) {
            try {
                Instruction *lineInstruction = Instruction::fromAssembly(this, line);
                this->addInstruction(lineInstruction);
            } catch (InvalidSyntaxException e) {
                this->reportParseError(sourceLineNumber, line, e);
                throw;
            }
        }
        sourceLineNumber += 1;
    }
}

std::string Program::asHackBinary() {
    std::stringstream compiledBinary; 

    for (Instruction *instruction : this->instructions) {
        compiledBinary << instruction->asHackBinary() << std::endl;
    }
    std::string compiledString = compiledBinary.str();

    // Remove the final newline.
    compiledString.erase(compiledString.length() - 1);
    return compiledString;
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

// Remove whitespace and comments
std::string Program::normalizeLine(std::string line) {
    static const boost::regex normalizeRegex("\\s|//.*");
    return boost::regex_replace(line, normalizeRegex, "");
}

void Program::addInstruction(Instruction *instr) {
    this->instructions.push_back(instr);
}

void Program::loadConstants() {
    this->addVariable(Variable("LCL", 1));
    this->addVariable(Variable("ARG", 2));
    this->addVariable(Variable("THIS", 3));
    this->addVariable(Variable("THAT", 4));
    this->addVariable(Variable("SCREEN", 16384));
    this->addVariable(Variable("KBD", 24576));

    // Load registers 0 - 15
    for (int i = 0; i < 15; ++i) {
        std::ostringstream regName;
        regName << "R" << i;
        this->addVariable(Variable(regName.str(), i));
    }
}

void Program::addVariable(Variable var) {
    this->variables.insert(std::make_pair(var.getName(), var));
}

bool Program::hasVariable(std::string varName) {
    return this->variables.count(varName) == 1;
}

Variable Program::getVariable(std::string varName) {
    return this->variables.at(varName);
}

int Program::getVariableValue(std::string varName) {
    if (!this->hasVariable(varName)) {
        Variable var(varName, this->getNextVariableAddress());
        this->addVariable(var);
    }
    return this->getVariable(varName).getValue();
}

int Program::getNextVariableAddress() {
    return this->nextVariableAddress++;
}

bool Program::lineIsLabel(std::string line) {
    return line.length() > 0 
        && line[0] == '(' 
        && line[line.length()-1] == ')';
}

void Program::reportParseError(
    int lineNum, std::string assembly, std::runtime_error error
) {
    std::cerr << "Error parsing \"" << assembly 
        << "\" (line " << lineNum << ") "
        << error.what() << std::endl;
}

}


#ifndef HACK_PROGRAM_H_ 
#define HACK_PROGRAM_H_

#include <string>
#include <stdexcept>
#include <vector>
#include <unordered_map>

#include "instruction.hh"

#include "variable.hh"

namespace hack {

class Instruction;

class Program {
  public:
    Program(std::string);
    std::string asHackBinary();
    std::vector<hack::Instruction*> asInstructions();
    int getVariableValue(std::string);

  private:
    int nextVariableAddress;
    std::vector<Instruction*> instructions;
    std::unordered_map<std::string, Variable> variables;
    std::string normalizeLine(std::string);
    std::string stripComments(std::string);
    void addInstruction(Instruction*);
    void addVariable(Variable);
    void loadConstants();
    void reportParseError(int, std::string, std::runtime_error);
    bool hasInstructions();
    bool hasVariable(std::string);
    bool lineIsLabel(std::string);
    int getNextVariableAddress();
    Variable getVariable(std::string);
};


}
#endif // HACK_PROGRAM_H_


#ifndef HACK_PROGRAM_H_ 
#define HACK_PROGRAM_H_

#include <string>
#include <stdexcept>
#include <vector>
#include "instruction.hh"

#include "label.hh"

namespace hack {

class Instruction;

class Program {
  public:
    Program(std::string);
    std::string asHackBinary();
    std::string asNormalizedAssembly();
    std::vector<hack::Instruction*> asInstructions();

  private:
    std::vector<Instruction*> instructions;
    std::vector<Label> labels;
    std::string normalizeAssembly(std::string);
    std::string normalizeLine(std::string);
    std::string stripWhitespace(std::string);
    std::string stripComments(std::string);
    std::string extractLabels(std::string);
    void addInstruction(Instruction*);
    void addLabel(Label);
    bool lineIsLabel(std::string);
    bool hasInstructions();
    void reportError(std::runtime_error);
};


}
#endif // HACK_PROGRAM_H_


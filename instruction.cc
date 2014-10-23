#include "instruction.hh"
#include <iostream>
#include "invalidsyntaxexception.hh"
#include "dinstruction.hh"
#include "ainstruction.hh"


namespace hack {

// hack::Instruction represents a single HACK assembly operation, eg. anything
// that can be translated into an opcode.
//
// hack::Instruction is an abstract class, made concrete by hack::AInstruction and 
// hack::DInstruction. 
//
// Instructions objects of any type should be created using Instruction::fromAssembly()

// Instruction::fromAssembly takes input as a single, non-empty HACK assembly instruction
// with no trailing or leading whitespace, or comments.
Instruction* Instruction::fromAssembly(std::string assemblySnippet) {
  char firstCharacter = assemblySnippet.at(0);
  bool isAInstruction = firstCharacter == '@';
  bool isDInstruction = firstCharacter == 'A' || firstCharacter == 'D';

  if (isAInstruction) {
    return new AInstruction(assemblySnippet);
  } else if (isDInstruction) {
    return new DInstruction(assemblySnippet);
  } else {
    throw InvalidSyntaxException();
  }
}

}



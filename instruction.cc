#include "instruction.hh"

#include <iostream>

#include "invalidsyntaxexception.hh"
#include "cinstruction.hh"
#include "ainstruction.hh"
#include "program.hh"


namespace hack {

// hack::Instruction represents a single HACK assembly operation, eg. anything
// that can be translated into an opcode.
//
// hack::Instruction is an abstract class, made concrete by hack::AInstruction 
// and hack::CInstruction. 
//
// Instructions objects of any type should be created using 
// Instruction::fromAssembly()

// Instruction::fromAssembly takes input as a single, non-empty,
// normalized (no whitespace or comments) HACK assembly.
//
// A reference to the program is also needed, as the content of an AInstruction
// depends on the program state.
Instruction* Instruction::fromAssembly(Program *program, std::string assemblySnippet) {
    char firstCharacter = assemblySnippet.at(0);
    bool isAInstruction = firstCharacter == '@';
    bool isCInstruction = firstCharacter == 'A' 
                       || firstCharacter == 'D' 
                       || firstCharacter == 'M';

    if (isAInstruction) {
        // AInstruction must know the locations of variables, so it needs a 
        // reference to the program.
        return new AInstruction(program, assemblySnippet);
    } else if (isCInstruction) {
        // CInstruction is stateless, so we don't need to pass the program
        return new CInstruction(assemblySnippet);
    } else {
        throw InvalidSyntaxException("Instruction is neither A nor D instruction.");
    }
}

void Instruction::anchor() {
}

}



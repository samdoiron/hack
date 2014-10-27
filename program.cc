#include "program.hh"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

// A hack program is a collection of instructions. These instructions can be 
// read from a file, or input as a string. All operations on a program as a whole
// perform the same operation on all of its instructions, and return a collection
// of the result.
namespace hack { 

// Program's constructor takes a string of HACK assembly.
Program::Program(std::string source) {
  std::string normalizedSource = this->normalizeAssembly(source);

  // Split the source into lines so we can create separate instructions.
  // If an invalid instruction is found, Instruction::fromAssembly will 
  // throw an InvalidSyntaxException.
  int newlineIndex;
  do {
    newlineIndex = normalizedSource.find("\n");
    std::string line = normalizedSource.substr(0, newlineIndex);
    this->instructions.push_back(Instruction::fromAssembly(line));
    normalizedSource.erase(0, newlineIndex + line.length());
  } while (newlineIndex != std::string::npos);

}

// Program::asHackBinary() translates all of the program's instructions 
// into binary strings, and returns a newline-delimited string containing
// the translations.
std::string Program::asHackBinary() {
  if (this->hasInstructions()) {
    std::stringstream compiledBinary; 

    for (Instruction *instruction : this->instructions) {
      compiledBinary << instruction->asHackBinary() << std::endl;
    }

    return compiledBinary.str();
  } else {
    return "";
  }
}

// Program::asNormalizedAssembly() translates all instructions into 
// (semi-)human-readable HACK assembly code, and returns a newline-delimited 
// string containing the translations.
//
// NOTE: This is not necessarily (or even likely) the same as the input.
std::string Program::asNormalizedAssembly() {
  if (this->hasInstructions()) {
    std::stringstream compiledBinary; 

    for (Instruction *instruction : this->instructions) {
      compiledBinary << instruction->asAssembly() << std::endl;
    }

    return compiledBinary.str();
  } else {
    return "";
  }
}

std::vector<Instruction*> Program::asInstructions() {
  return this->instructions;
}

// --- private

// Program::normalizeAssembly() converts input assembly into a consistent form,
// by stripping away excess whitespace and comments.
std::string Program::normalizeAssembly(std::string assembly) {
  std::string withoutWhitespace, withoutComments;

  withoutWhitespace = this->stripWhitespace(assembly);
  withoutComments   = this->stripComments(withoutWhitespace);

  return withoutComments;
}

// Program::stripWhitespace() removes all leading and trailing whitespace
// from the program. 
//
// NOTE: this does not remove optional whitespace from instructions themselves.
// std::string.
std::string Program::stripWhitespace(std::string assembly) {
  std::string stripped;

  stripped = this->stripCharacter(assembly, " ");
  stripped = this->stripCharacter(assembly, "\t");
  stripped = this->stripCharacter(assembly, "\n");

  return stripped;
}

std::string Program::stripCharacter(std::string full, std::string character) {
  full.erase(0, full.find_first_not_of(character));
  full.erase(0, full.find_last_not_of(character) + 1);
  return full;
}

// Program::stripComments() removes all "//" style comments from the given
// std::string.
std::string Program::stripComments(std::string assembly) {
  return assembly;
}

bool Program::hasInstructions() {
  return this->instructions.size() == 0;
}

}


#include "program.hh"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "invalidsyntaxexception.hh"

// A hack program is a collection of instructions. These instructions can be 
// read from a file, or input as a string. All operations on a program as a whole
// perform the same operation on all of its instructions, and return a collection
// of the result.
namespace hack { 

// Program's constructor takes a string of HACK assembly.
Program::Program(std::string source) {
  this->assemblySource = this->normalizeAssembly(source);
}

// Program::asHackBinary() translates all of the program's instructions 
// into binary strings, and returns a newline-delimited string containing
// the translations.
std::string Program::asHackBinary() {
  if (this->assemblySource == "") {
    return "";
  } else {
    throw InvalidSyntaxException();
  }
}

// Program::asNormalizedAssembly() translates all instructions into 
// (semi-)human-readable HACK assembly code, and returns a newline-delimited 
// string containing the translations.
//
// NOTE: This is not necessarily (or even likely) the same as the input.
std::string Program::asNormalizedAssembly() {
  if (this->assemblySource == "") {
    return "";
  } else {
    throw InvalidSyntaxException();
  }
}

std::vector<hack::Instruction*> Program::asInstructions() {
  std::vector<hack::Instruction*> instructions;
  return instructions;
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

// Program::stripComments() removes all "//" style comments from the given
// std::string.
std::string Program::stripComments(std::string assembly) {
  return assembly;
}

// Program::stripWhitespace() removes all leading and trailing whitespace
// from the program. 
//
// NOTE: this does not remove optional whitespace from instructions themselves.
// std::string.
std::string Program::stripWhitespace(std::string assembly) {
  return assembly;
}

}


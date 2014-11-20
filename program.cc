#include "program.hh"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

#include "label.hh"
#include "instruction.hh"
#include "invalidsyntaxexception.hh"

// A hack program is a collection of instructions. These instructions can be 
// read from a file, or input as a string. All operations on a program as a whole
// perform the same operation on all of its instructions, and return a collection
// of the result.
namespace hack { 

// Program's constructor takes a string of HACK assembly.
Program::Program(std::string source) {
  std::string normalizedSource = this->normalizeAssembly(source);
  std::string withoutLabels = this->extractLabels(normalizedSource);
  this->loadInstructions(withoutLabels);
}

// Program::asHackBinary() translates all of the program's instructions 
// into binary strings, and returns a newline-delimited string containing
// the translations.
std::string Program::asHackBinary() {
  std::stringstream compiledBinary; 

  std::cout << "Read " << this->instructions.size() << " instructions" << std::endl;
  for (Instruction *instruction : this->instructions) {
    compiledBinary << instruction->asHackBinary() << std::endl;
  }

  return compiledBinary.str();
}

// Program::asNormalizedAssembly() translates all instructions into 
// (semi-)human-readable HACK assembly code, and returns a newline-delimited 
// string containing the translations.
//
// NOTE: This is not necessarily (or even likely) the same as the input.
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

// Program::normalizeAssembly() converts input assembly into a consistent form,
// by stripping away excess whitespace and comments.
std::string Program::normalizeAssembly(std::string assembly) {
  std::string withoutWhitespace, normalized, line;
  std::stringstream inputStream(assembly), outputStream;

  while (getline(inputStream, line)) {
    if (!line.empty()) {
      outputStream << this->normalizeLine(line) << std::endl;
    }
  }

  return outputStream.str();
}

std::string Program::normalizeLine(std::string line) {
  std::string withoutWhitespace, normalized;

  withoutWhitespace = this->stripWhitespace(line);
  normalized        = this->stripComments(line);

  return normalized;
}

// Program::stripWhitespace() removes all whitespace from the program. 
std::string Program::stripWhitespace(std::string assembly) {
  std::string stripped = assembly;

  size_t i = 0;
  while (i < assembly.length()) {
    char currentChar = stripped[i];
    if (isspace(currentChar) && currentChar != '\n') {
        std::cout << "deleting " << currentChar << std::endl;
        stripped.erase(i);
    } else {
      ++i;
    }
  }

  return stripped;
}

// Program::stripComments() removes all "//" style comments from the given
// std::string.
std::string Program::stripComments(std::string assembly) {
  std::string stripped = assembly;

  for (size_t i = 0; (i + 1) < assembly.length(); ++i) {
    if (assembly[i] == '/' && assembly[i+1] == '/') {
      stripped.erase(i, stripped.size());
      break;
    }
  }

  return stripped;
}

// Remove and store all label values from the given assembly;
std::string Program::extractLabels(std::string assembly) {
  std::stringstream inputStream(assembly), outputStream;
  std::string line;
  int lineNumber = 1;

  while (getline(inputStream, line)) {
    if (Label::isValid(line)) {
      // Remove the trailing ":"
      line.erase(line.length() - 1);
      Label label(line, lineNumber);
      this->loadLabel(label);
    } else {
      outputStream << line;
    }
    lineNumber += 1;
  }

  return outputStream.str();
}

void Program::loadLabel(Label label) {
    this->labels.push_back(label);
}

void Program::loadInstructions(std::string assembly) {
    std::stringstream inputStream(assembly);
    std::string line;
    while (getline(inputStream, line)) {
        std::cout << "Instruction line is \"" << line << "\"" << std::endl;
        try {
            this->instructions.push_back(Instruction::fromAssembly(this, line));
        } catch (InvalidSyntaxException e) {
            std::stringstream errorMessage;
            errorMessage << "Error loading instruction \"" << line << "\": " << e.what();
            throw InvalidSyntaxException(errorMessage.str());
        }
    }
}

}


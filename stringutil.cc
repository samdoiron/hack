
#include "stringutil.hh"

#include <string>
#include <vector>
#include <algorithm>

namespace hack {

std::string trim(std::string input) {
  std::vector<char> whitespace = {' ', '\n', '\t'};
  return trimCharacters(input, whitespace);
}

std::string trimCharacter(std::string toTrim, char character) {
  std::vector<char> characters = {character};
  return trimCharacters(toTrim, characters);
}

std::string leftTrimCharacter(std::string toTrim, char character) {
  std::vector<char> characters = {character};
  return leftTrimCharacters(toTrim, characters);
}

std::string rightTrimCharacter(std::string toTrim, char character) {
  std::vector<char> characters = {character};
  return rightTrimCharacters(toTrim, characters);
}

std::string trimCharacters(std::string toTrim, std::vector<char> characters) {
  std::string leftTrimmed, fullyTrimmed;

  leftTrimmed = leftTrimCharacters(toTrim, characters);
  fullyTrimmed = rightTrimCharacters(leftTrimmed, characters);

  return fullyTrimmed;
}

std::string leftTrimCharacters(std::string toTrim, std::vector<char> characters) {
  // Special case, can't have seperate slice beginning and ending.
  if (toTrim == "") {
    return "";
  }
  size_t sliceEnd = 0;

  while (sliceEnd < toTrim.size()) {
    // Break unless the current character is among those to be trimmed
    auto trimmedChar = std::find(characters.begin(), characters.end(), toTrim[sliceEnd]);
    bool shouldTrim = trimmedChar != characters.end();
    if (shouldTrim) {
      ++sliceEnd;
    } else {
      break;
    }
  }
  toTrim.erase(0, sliceEnd);
  return toTrim;
}

std::string rightTrimCharacters(std::string toTrim, std::vector<char> characters) {
  // Special case, can't have seperate slice beginning and ending.
  if (toTrim == "") {
    return "";
  }

  size_t sliceBegin = toTrim.size();

  while (sliceBegin > 0) {
    // Break unless the current character is among those to be trimmed
    auto trimmedChar = std::find(characters.begin(), characters.end(), toTrim[sliceBegin - 1]);
    bool shouldTrim = trimmedChar != characters.end();
    if (shouldTrim) {
      --sliceBegin;
    } else {
      break;
    }
  }

  toTrim.erase(sliceBegin, toTrim.size());

  return toTrim;
}

}



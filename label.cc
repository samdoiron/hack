
#include <string>

#include "label.hh"

namespace hack {

Label::Label(std::string labelName, int labelAddress) {
  this->name    = labelName;
  this->address = labelAddress;
}

/* static */ bool Label::isValid(std::string maybeLabel) {
  return !maybeLabel.empty() && maybeLabel[maybeLabel.length() - 1] == 0;
}

std::string Label::getName() {
  return "unimplmented";
}

int Label::getAddress() {
  return -1;
}

}


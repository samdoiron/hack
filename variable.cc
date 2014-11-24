
#include <string>

#include "variable.hh"

namespace hack {

Variable::Variable(std::string varName, int varValue) {
  this->name    = varName;
  this->value = varValue;
}

std::string Variable::getName() {
    return this->name;
}

int Variable::getValue() {
    return this->value;
}

}


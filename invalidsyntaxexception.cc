#include "invalidsyntaxexception.hh"
#include <string>

namespace hack {
  InvalidSyntaxException::InvalidSyntaxException(std::string mess) {
    this->message = mess;
  }

  std::string InvalidSyntaxException::what() throw() {
    return this->message;
  }

}

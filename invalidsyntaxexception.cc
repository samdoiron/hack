#include "invalidsyntaxexception.hh"
#include <string>

namespace hack {

InvalidSyntaxException::InvalidSyntaxException(std::string message)
  : std::runtime_error(message) { }

}

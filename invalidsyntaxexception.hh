
#include <string>

namespace hack {

class InvalidSyntaxException {
  public:
    InvalidSyntaxException(std::string message="Invalid Syntax");
    std::string what() throw();

  private:
    std::string message;
};

}


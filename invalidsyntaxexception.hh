
#include <string>

namespace hack {

class InvalidSyntaxException : public std::runtime_error {
  public:
    InvalidSyntaxException(std::string);
  private:
    virtual void anchor(int);
};

}


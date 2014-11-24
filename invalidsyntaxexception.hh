
#ifndef HACK_INVALIDSYNTAXEXCEPTION_H_
#define HACK_INVALIDSYNTAXEXCEPTION_H_

#include <string>

namespace hack {

class InvalidSyntaxException : public std::runtime_error {
  public:
    InvalidSyntaxException(std::string);
  private:
    virtual void anchor();
};

}

#endif


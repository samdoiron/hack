#ifndef HACK_LABEL_H_
#define HACK_LABEL_H_

#include <string>

namespace hack {

class Variable {
  public:
    Variable(std::string, int);
    std::string getName();
    int getValue();

  private:
    std::string name;
    int value;
};

}

#endif // HACK_LABEL_H_


#ifndef HACK_LABEL_H_
#define HACK_LABEL_H_

#include <string>

namespace hack {

class Label {
  public:
    static bool isValid(std::string);

    Label(std::string, int);
    int getAddress();
    std::string getName();

  private:
    std::string name;
    int address;
};

}

#endif // HACK_LABEL_H_


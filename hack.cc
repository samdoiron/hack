
#include <iostream>
#include <string>
#include <stdexcept>

#include "program.hh"
#include "invalidsyntaxexception.hh"

int main(void) {
    try {
        hack::Program program("@foo");
    } catch (hack::InvalidSyntaxException e) {
        std::cout << "Invalid Syntax!" << std::endl;
    }
    return 0;
}


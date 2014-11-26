
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <fstream>

#include "program.hh"
#include "invalidsyntaxexception.hh"

int main(void) {
    std::ostringstream sourceStream;
    sourceStream << std::cin.rdbuf();
    std::string source = sourceStream.str();
    try {
        hack::Program program(sourceStream.str());
        std::cout << program.asHackBinary() << std::endl;
        return 0;
    } catch (hack::InvalidSyntaxException e) {
        return 1;
    }
}


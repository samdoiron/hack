
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

#include <boost/algorithm/string.hpp>

#include "program.hh"
#include "invalidsyntaxexception.hh"

int main(void) {

    // Read HACK source from stdin (until EOF)
    std::stringstream sourceStream;
    sourceStream << std::cin.rdbuf();
    std::string source = sourceStream.str();

    try {
        hack::Program program(source);
        std::cout << program.asHackBinary() << std::endl;
    } catch (hack::InvalidSyntaxException e) {
        std::cout << "Invalid Syntax! -> " << e.what() << std::endl;
    }
    return 0;
}


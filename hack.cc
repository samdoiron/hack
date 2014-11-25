
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <fstream>

#include "program.hh"
#include "invalidsyntaxexception.hh"

int main(int argc, char *argv[]) {
    std::ostringstream sourceStream;
    if (argc > 1) {
        std::ifstream fileInput(argv[1]);
        sourceStream << fileInput.rdbuf();
    } else {
        std::cout << argc <<  std::endl;
        sourceStream << std::cin.rdbuf();
    }
    try {
        hack::Program program(sourceStream.str());
        std::cout << program.asHackBinary() << std::endl;
        return 0;
    } catch (hack::InvalidSyntaxException e) {
        return 1;
    }
}


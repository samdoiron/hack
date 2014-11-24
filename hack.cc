
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <fstream>

#include "program.hh"
#include "invalidsyntaxexception.hh"

int main(int argc, char *argv[]) {
    std::ostringstream sourceStream;

    // Input from file argument
    if (argc > 1) {
        std::ifstream fileInput(argv[1]);
        sourceStream << fileInput.rdbuf();
    } else {
        // Input from STDIN
        sourceStream << std::cin.rdbuf();
    }

    hack::Program program(sourceStream.str());
    std::cout << program.asHackBinary() << std::endl;
    return 0;
}


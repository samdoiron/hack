
#include <string>
#include <vector>

namespace hack {

std::string trim(std::string);

std::string trimCharacter(std::string, char);

std::string leftTrimCharacter(std::string, char);

std::string rightTrimCharacter(std::string, char);

std::string trimCharacters(std::string, std::vector<char>);

std::string leftTrimCharacters(std::string, std::vector<char>);

std::string rightTrimCharacters(std::string, std::vector<char>);

std::vector<std::string> split(std::string, char);

}


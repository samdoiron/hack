#include <string>
#include <iostream>
#include "stringutil.hh"
#include "catch.h"

SCENARIO("Strings can be trimmed", "[stringutil]") {

  GIVEN("An empty string") {
    std::string emptyString = "";
    std::vector<char> characters;
    characters.push_back('a');

    WHEN("whitespace characters are trimmed") {
      std::string trimmed = hack::trim(emptyString);
      THEN("the result is empty") {
        REQUIRE(trimmed == "");
      }
    }

    WHEN("a character is trimmed") {
      std::string trimmed = hack::trimCharacter(emptyString, 'a');
      THEN("the result is empty") {
        REQUIRE(trimmed == "");
      }
    }

    WHEN("a character is left trimmed") {
      std::string trimmed = hack::leftTrimCharacter(emptyString, 'a');
      THEN("the result is empty") {
        REQUIRE(trimmed == "");
      }
    }

    WHEN("a character is right trimmed") {
      std::string trimmed = hack::rightTrimCharacter(emptyString, 'a');
      THEN("the result is empty") {
        REQUIRE(trimmed == "");
      }
    }

    WHEN("multiple characters are trimmed") {
      std::string trimmed = hack::trimCharacters(emptyString, characters);
      THEN("the result is empty") {
        REQUIRE(trimmed == "");
      }
    }

    WHEN("multiple characters are left trimmed") {
      std::string trimmed = hack::leftTrimCharacters(emptyString, characters);
      THEN("the result is empty") {
        REQUIRE(trimmed == "");
      }
    }

    WHEN("multiple characters are right trimmed") {
      std::string trimmed = hack::rightTrimCharacters(emptyString, characters);
      THEN("the result is empty") {
        REQUIRE(trimmed == "");
      }
    }
  }

  GIVEN("a string of identical non-whitespace characters") {
    std::string identString = "__________";

    WHEN("a non-contained character is trimmed") {
      std::vector<char> nonexistant;
      nonexistant.push_back('%');
      THEN("the result should be identical") {
        CHECK(hack::trim(identString) == identString);
        CHECK(hack::trimCharacter(identString, '%') == identString);
        CHECK(hack::leftTrimCharacter(identString, '%') == identString);
        CHECK(hack::rightTrimCharacter(identString, '%') == identString);
        CHECK(hack::trimCharacters(identString, nonexistant) == identString);
        CHECK(hack::leftTrimCharacters(identString, nonexistant) == identString);
        REQUIRE(hack::rightTrimCharacters(identString, nonexistant) == identString);
      }
    }

    WHEN("a contained character is left trimmed") {
      std::vector<char> existant;
      existant.push_back(identString[0]);

      THEN("the result should be empty") {
        CHECK(hack::trim("") == "");
        CHECK(hack::trimCharacter(identString, '_') == "");
        CHECK(hack::leftTrimCharacter(identString, '_') == "");
        CHECK(hack::rightTrimCharacter(identString, '_') == "");
        CHECK(hack::trimCharacters(identString, existant) == "");
        CHECK(hack::leftTrimCharacters(identString, existant) == "");
        REQUIRE(hack::rightTrimCharacters(identString, existant) == "");
      }
    }
  }
}

SCENARIO("strings can be split", "[stringutil]") {
  WHEN("an empty string is split") {
    std::vector<std::string> result = hack::split("", '|');
    THEN("the result should contain a single empty string") {
      REQUIRE(result.size() == 1);
      CHECK(result[0] == "");
    }
  }

  WHEN("a string does not contain the split character") {
    std::vector<std::string> result = hack::split("12345", '|');

    THEN("the result contains only the original string") {
      REQUIRE(result.size() == 1);
      CHECK(result[0] == "12345");
    }
  }

  WHEN("a string contains the split character once") {
    std::vector<std::string> result = hack::split("123|45", '|');
    THEN("the elements should be those on either side of the split character") {
      REQUIRE(result.size() == 2);
      CHECK(result[0] == "123");
      CHECK(result[1] == "45");
    }
  }

  WHEN("the string contains the split character multiple times") {
    std::vector<std::string> result = hack::split("123|456|7", '|');
    THEN("the result should include only all split sections") {
      CAPTURE(result[0]);
      CAPTURE(result[1]);
      REQUIRE(result.size() == 3);
      CHECK(result[0] == "123");
      CHECK(result[1] == "456");
      CHECK(result[2] == "7");
    }
  }

  WHEN("a string ends with the split character") {
    std::vector<std::string> result = hack::split("1|23|", '|');
    THEN("the result should not end in an empty string") {
      REQUIRE(result.size() == 2);
      CHECK(result[result.size() - 1] != "");
    }
  }

  WHEN("a string has two split characters in a row") {
    std::vector<std::string> result = hack::split("1||2", '|');
    THEN("the split should not contain an empty string") {
      REQUIRE(result.size() == 2);
      CHECK(result[0] == "1");
      CHECK(result[1] == "2");
    }
  }

  WHEN("a string begins with the split character") {
    std::vector<std::string> result = hack::split("|234", '|');
    THEN("the result should not end with an empty string") {
      REQUIRE(result.size() == 1);
      CHECK(result[0] == "234");
    }
  }

  WHEN("a string contains only the split character") {
    std::vector<std::string> result = hack::split("|||||||", '|');
    THEN("the result should be empty") {
      REQUIRE(result.size() == 0);
    }
  }

}


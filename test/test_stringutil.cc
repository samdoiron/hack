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

/* SCENARIO("strings can be split", "[stringutil]") { */
/*   std::string splitChar = "|"; */

/*   GIVEN("an empty string") { */
/*     std::string emptyString = ""; */
/*     WHEN("the string is split") { */
/*       std::vector<std::string> result = hack::split(emptyString, splitChar); */
/*       THEN("the result should contain a single empty string") { */
/*         CHECK(result[0] == ""); */
/*         REQUIRE(result.size() == 1); */
/*       } */
/*     } */
/*   } */

/*   GIVEN("an empty split character and non-empty string") { */
/*     WHEN("the string is split") { */
/*       THEN("the result should contain the original string") { */
/*       } */
/*     } */
/*   } */

/*   GIVEN("a string that does not contain the split character") { */
/*     std::string testString = "12345"; */
/*   } */

/*   GIVEN("a string that contains the split character once") { */
/*     std::string testString = "123|567"; */
/*   } */

/*   GIVEN("a string that contains multiple split characters") { */
/*     std::string testString = "123|567|9"; */
/*   } */

/*   GIVEN("a string that ends with the split character") { */
/*     std::string testString = "12|3|"; */

/*     WHEN("the string is split") { */
/*       THEN("the result should not end in an empty string") { */

/*       } */
/*     } */
/*   } */

/*   GIVEN("a string that has two split characters in a row") { */
/*     WHEN("the string is split") { */
/*       THEN("the split should not contain an empty string") { */

/*       } */
/*     } */
/*   } */

/*   GIVEN("a string that begins with the split character") { */
/*     std::string testString = "|234"; */

/*     WHEN("the string is split") { */
/*       THEN("the result should not end in an empty string") { */
/*       } */
/*     } */
/*   } */

/* } */


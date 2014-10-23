#include <string>
#include "catch.h"
#include "program.hh"

SCENARIO("Programs can be assembled", "[program]") {

  GIVEN("An empty program") {
    hack::Program program("");

    WHEN("You retrieve the binary translation") {
      std::string translated = program.asHackBinary();

      THEN("The result should be empty") {
        REQUIRE(translated == "");
      }
    }
  }

  GIVEN("An invalid program") {
    THEN("Creation of the program object should fail") {
      REQUIRE_THROWS_AS(hack::Program program("bad code"), hack::InvalidSyntaxException);
    }
  }

}

SCENARIO("Programs can be disassembled", "[program]") {

  GIVEN("An empty program") {
    hack::Program program("");

    WHEN("You retrieve the assembly source") {
      std::string source = program.asNormalizedAssembly();

      THEN("The result should be empty") {
        REQUIRE(source == "");
      }
    }
  }

  GIVEN("An invalid program") {
    hack::Program program("this string is invalid HACK assembly");
  }

}


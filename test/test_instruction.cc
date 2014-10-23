#include <string>
#include "catch.h"
#include "program.hh"

SCENARIO("Instructions can be assembled", "[program]") {
  GIVEN("An empty instruction") {
    THEN("Creation of the instruction object should fail") {
      REQUIRE_THROWS_AS(hack::Instruction::fromAssembly(""), hack::InvalidSyntaxException);
    }
  }

  GIVEN("An invalid instruction") {
    THEN("Creation of the instruction object should fail") {
      REQUIRE_THROWS_AS(hack::Instruction::fromAssembly("bad code"), hack::InvalidSyntaxException);
    }
  }

}

SCENARIO("Instructions can be disassembled", "[program]") {
}


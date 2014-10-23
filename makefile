CPPFLAGS = -c -Weverything -Werror -pedantic
TESTFLAGS = -I .
LDFLAGS = -g

.PHONY: clean test

all: hack

program.o: program.hh program.cc
	clang++ $(CPPFLAGS) -o program.o program.cc

hack.o: hack.cc
	clang++ $(CPPFLAGS) -o hack.o hack.cc

hack: program.o hack.o
	clang++ $(LDFLAGS) -o hack program.o hack.o

test_header.o: test/test_header.cc test/catch.h
	clang++ test/test_header.cc -c -o test/test_header.o

test:
	make $(file).o
	clang++ $(TESTFLAGS) test/test_header.o $(file).o test/test_$(file).cc -o test/$(file)
	./test/$(file)
	rm test/$(file)


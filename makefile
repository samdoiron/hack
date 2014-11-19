CPPFLAGS = -c -std=c++11 -Weverything -pedantic -Wno-c++98-compat -g -Wno-padded
TESTFLAGS = -std=c++11 -I .
LDFLAGS = -g

.PHONY: clean test debug

all: hack

program.o: program.hh program.cc
	clang++ $(CPPFLAGS) -o program.o program.cc

hack.o: hack.cc
	clang++ $(CPPFLAGS) -o hack.o hack.cc

hack: program.o hack.o
	clang++ $(LDFLAGS) -o hack *.o

test_header.o: test/test_header.cc test/catch.h
	clang++ test/test_header.cc -c -o test/test_header.o

instruction.o: program.o instruction.hh instruction.cc 
	clang++ $(CPPFLAGS) -o instruction.o instruction.cc

label.o: label.hh label.cc
	clang++ $(CPPFLAGS) -o label.o label.cc

invalidsyntaxexception.o: invalidsyntaxexception.cc invalidsyntaxexception.hh
	clang++ $(CPPFLAGS) -o invalidsyntaxexception.o invalidsyntaxexception.cc

debug:
	make $(file).o
	clang++ $(TESTFLAGS) test/test_header.o $(file).o test/test_$(file).cc -o test/$(file)

test:
	make $(file).o
	clang++ $(TESTFLAGS) test/test_header.o $(file).o test/test_$(file).cc -o test/$(file)
	./test/$(file)
	rm test/$(file)


clean:
	rm *.o


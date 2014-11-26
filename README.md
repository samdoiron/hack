
Hack Assembly Compiler
======================

Requirements
------------
Compilation requires the Boost v1.5.7 libraries to be installed. As 1.5.7 is
the latest version, these can be obtained by using a package manager on UNIX
environments.

On OSX (using homebrew):
  brew install boost

On Linux (using apt):
  sudo apt-get install libboost-all-dev

Building
--------

The project comes with a working CMake file. To compile on a UNIX environment, 
use you can simply use `make` from the main directory.

If that fails, or you need to compile on a different platform, then you can
use the provided `CMakeLists.txt` file to generate build files.

Performance
-----------

Local testing shows that files of the maximum possible size for the HACK computer
assemble correctly in ~0.1s

The largest optimization that was done was to cache instructions and their comipled
form internally. In practise, this resulted in a ~33% speedup (0.15s -> 0.1s) 
in the worst case.

Other techniques, such as pre-calculating the result for every possible HACK assembly
instruction were found to be less effective.



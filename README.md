# PIMPL Idiom Example
A project in CMake that uses PIMPL idiom to hide the implementation of the Graph class.
In addition, the user can choose to use the default implementation (from Lemon Library) or Boost Graph.

## Generating Makefiles and Building using Boost Graph
cmake -DUSE_BOOST:BOOL=ON
make

## Generating Makefiles and Building using the default implementation (from Lemon Library)
cmake
make

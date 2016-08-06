# PIMPL Idiom Example
A project in CMake that uses PIMPL idiom to hide the implementation of the Graph class.
In addition, the user can choose to use the default implementation (from [Lemon Library](http://lemon.cs.elte.hu/)) or [Boost Graph](http://www.boost.org/).

## Generating Makefiles

### Using the Default Graph Implementation (Lemon Graph)
`cmake`
`make`

### Using Boost Graph
`cmake -DUSE_BOOST:BOOL=ON`
`make`



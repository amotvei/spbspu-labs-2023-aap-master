#ifndef INPUTARRAY_HPP
#define INPUTARRAY_HPP
#include <iosfwd>
#include <fstream>
#include <iostream>
#include <algorithm>

namespace readArray
{
  void inputArray(std::istream & in, int * m, size_t s, size_t toRead);
}
#endif
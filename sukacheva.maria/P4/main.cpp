#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "matrix.hpp"
#include "InputArray.hpp"

int main(int argc, char** argv)
{
  using namespace sukacheva;

  if (argc != 4)
  {
    std::cerr << "Wrong number of elements.\n";
    return 1;
  }

  char* end = nullptr;
  long long num = std::strtoll(argv[1], std::addressof(end), 10);
  if (*end != '\0')
  {
    std::cout << "Input error: argument is not a number.\n";
    return 3;
  }

  size_t rows = 0, cols = 0;
  std::ifstream input(argv[2]);
  try
  {
    input >> rows;
    input >> cols;
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Cannot read an input.\n";
    return 2;
  }
  if (cols == 0 || rows == 0)
  {
    return 0;
  }
  const int sizeOfMatrix = rows * cols;
  int staticMatrix[10000];
  int* resultMatrix = (num == 1) ? staticMatrix : new int[sizeOfMatrix];
  size_t result = inputMatrix(input, resultMatrix, sizeOfMatrix, sizeOfMatrix);
  if (!(result == sizeOfMatrix))
  {
    std::cerr << "Cannot read an array. Read " << result << " elements.\n";
    if (num == 2)
    {
      delete[] resultMatrix;
    }
    return 2;
  }

  if (num == 2)
  {
    delete[] resultMatrix;
  }
  else
  {
    std::cerr << "Argument is out of range. \n";
    return 1;
  }
  std::ofstream output(argv[3]);
  output << MaxSideDiagonal(resultMatrix, rows) << "\n" << upperTriangularMatrix(resultMatrix, cols, rows);
  return 0;
}

#include <iostream>
#include <fstream>
#include <random>

int main()
{
  // rand
  std::random_device rn_dev; // seed
  std::mt19937  generator(rn_dev()); // engine
  std::uniform_int_distribution<int> distribute(32,126); // implement

  int comp_val;
  unsigned short rows, cols;
  std::cout << "input rows, cols: ";
  std::cin >> rows >> cols;
  comp_val = rows * cols;

  std::ofstream outputFile;
  outputFile.open("./data/numbers.txt");
  for(int i {0}; i < comp_val; i++) {
    outputFile << static_cast<char>(distribute(generator)) << ((i + 1) % cols ? ' ' : '\n');
  }
  outputFile << '\n';
  std::cout << std::endl;
}

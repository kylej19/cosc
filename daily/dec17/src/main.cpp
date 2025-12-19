#include <iostream>
#include <fstream>
#include <random>

int main()
{
  // rand
  std::random_device rn_dev; // seed
  std::mt19937  generator(rn_dev()); // engine
  std::uniform_int_distribution<int> distribute(100,999); // implement

  int comp_val, line_count;
  std::cout << "input number of lines: ";
  std::cin >> line_count;
  comp_val = line_count * 16;

  std::ofstream outputFile;
  outputFile.open("./data/numbers.txt");
  for(int i {0}; i < comp_val; i++) {
    outputFile << distribute(generator) << ((i + 1) % 16 ? ' ' : '\n');
  }
  outputFile << '\n';
  std::cout << std::endl;
}

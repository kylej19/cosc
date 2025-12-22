#include <iostream>
#include <fstream>
#include <random>

int main()
{
  // rand
  std::random_device rn_dev; // seed
  std::mt19937  generator(rn_dev()); // engine
  std::uniform_int_distribution<int> distribute(33,91); // implement

  int comp_val;
  unsigned short rows, cols;
  const std::string FILENAME = "./data/list.txt";
  std::cout << "input cols, rows: ";
  std::cin >> cols >> rows;
  comp_val = rows * cols;

  std::ofstream outputFile;
  outputFile.open(FILENAME);
  for(int i {0}; i < comp_val; i++) {
    outputFile << static_cast<char>(distribute(generator)) << ((i + 1) % cols ? "" : "\n");
  }
  outputFile << '\n';
  outputFile.close();
  std::cout << "wrote file " << FILENAME << std::endl;

  std::ifstream inputFile(FILENAME);
  std::string line;
  if(inputFile)
    {
      while(inputFile >> line)
	{
	  std::cout << line << std::endl;
	}
      inputFile.close();
    }
}

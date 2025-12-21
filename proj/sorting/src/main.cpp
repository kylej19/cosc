#include <iostream>
#include <fstream>

int main()
{
  // sorting algorithms
  std::ifstream inputFile("data/chars.txt");
  char c;
  unsigned long counter = 0;
  std::cout << "counting chars in file...\n";
  while(inputFile >> c)
    {
      ++counter;
    }
  inputFile.close();

  std::cout << "initializing dynamic array...\n";
  char* map = new char[counter];
  
  std::ifstream readFile;
  readFile.open("data/chars.txt");
  for(unsigned long i {0}; i < counter; i++)
    {
      readFile >> map[i];
      std::cout << map[i] << std::endl;
    }
  std::cout << counter << std::endl;
}

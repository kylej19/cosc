//program: tables.cpp
//author: kyle johnson
//date: 10-27 (whoops)

#include<iostream>
#include<iomanip>
#include<random>

int main() {
  
  // random number generator in case user fails to input (integers)
  // also really userful for testing
  std::random_device rd;
  std::mt19937  gen(rd());
  std::uniform_int_distribution<int> distrib(1,12);

  // variables to hold our dimensions
  // they could be const but rng was easier without, i'm leaving it
  int rows, cols;

  // ask user for rows and columns
  std::cout << "enter in the amount of rows and columns you need in your multiplication table: ";
  
  // gemini told me this was a common error checking method when i was working on the last assignment
  // it only triggers if a non-integer, non-whitespace character invalidates the type
  if (!(std::cin >> rows >> cols))
    {
      rows = distrib(gen);
      cols = rows;
    }


  // prints a header row 
  for(int h = 0; h <= cols; ++h)
    { std::cout << std::setw(4) << std::left << h << "|"; }

  std::cout << "\n";
  
  for(int i = 1; i <= rows; ++i)
    {
      std::cout << std::setw(4) << std::left <<  i << "|";
      for(int j = 1; j <= cols; ++j)
      {
	std::cout << std::setw(4) << std::right << i*j <<"|";
      }
      std::cout <<"\n";
    }


  std::cout << std::endl;
	  
}

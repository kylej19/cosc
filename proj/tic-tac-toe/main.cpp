#include <iostream>
#include <iomanip>
#include <random>

int main()
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distrib(0,2);

  int board[3][3] = {
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0} };

  for(unsigned long int row = 0; row < (sizeof(board)/sizeof(board[0]));row++) {
      for(unsigned long int col = 0; col < (sizeof(board[0])/sizeof(board[0][0]));col++) {
	std::cout << std::setw(4) << "|" << board[row][col] << "|";
	}
      std::cout << "\n";      
    }
  
}

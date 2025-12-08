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
  unsigned short total_rows = sizeof(board)/sizeof(board[0]);
  unsigned short total_cols = sizeof(board[0])/sizeof(board[0][0]);
  
  for(unsigned int row = 0; row < total_rows;row++) {
      for(unsigned int col = 0; col < total_cols;col++) {
	std::cout << std::setw(4) << "|" << board[row][col] << "|";
	}
      std::cout << "\n";      
    }  

}



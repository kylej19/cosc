#include <iostream>
#include <iomanip>
#include <random>

int main()
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distrib(0,2);

  const unsigned short SIZE = 3;
  char playerChar, computerChar;

  char board[SIZE][SIZE] =
    {
      {' ', ' ', ' '},
      {' ', ' ', ' '},
      {' ', ' ', ' '}
    };


  std::cout << "welcome to tic-tac-toe"
	    << "\n"
	    << "\n";
  std::cout << "which letter do you want to be? [X/O]\n";
  std::cin >> playerChar;

  switch(playerChar)
    {
    case 'X' :
      computerChar = 'O';
      break;
    case 'O' :
      computerChar = 'X';
      break;
    }
  
  std::cout << "your choice was " << playerChar << "\nthe computer will be " << computerChar << std::endl;
  
  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      std::cout << board[i][j] << ((j + 1) % SIZE ? '|' : '\n');
    } }  
}



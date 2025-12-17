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

  char board[SIZE][SIZE];


  for(int row = 0; row < SIZE; row++) {
    for(int col = 0; col < SIZE; col++) {
      board[row][col] = ' ';
    } }


  std::cout << "welcome to tic-tac-toe"
	    << "\n"
	    << "please choose which letter you\n";
  std::cout << "would like to play as\n";
  while(!(playerChar == 'x' || playerChar == 'o')) {
    std::cout << "enter selection [x/o]: ";
    std::cin >> playerChar;
  }

  switch(playerChar)
    {
    case 'x' :
      computerChar = 'o';
      break;
    case 'o' :
      computerChar = 'x';
      break;
    }
  
  std::cout << "your choice was " << playerChar << "\nthe computer will be " << computerChar << std::endl;

  std::cout << "use the map to choose your first move: \n";
  char map = '1';  
  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      std::cout << map++ << ((j + 1) % SIZE ? '|' : '\n');
    } }  
}



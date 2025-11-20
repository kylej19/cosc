#include <iostream>
#include <iomanip>
#include <random>

int main()
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distrib(0,2);

  int board[3][3] =
    {
      {-1, -1, -1},
      {-1, -1, -1},
      {-1, -1, -1}
    };
}

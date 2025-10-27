//program
//author
//date

#include<iostream>
#include<iomanip>
#include<random>

int main() {
  
  // random number generator in case user fails to input
  std::random_device rd;
  std::mt19937  gen(rd());
  std::uniform_int_distribution<int> distrib(1,12);
  
  int rows, cols;
  
  // ask user for rows and columns
  std::cout << "enter in the amount of rows and columns you need in your multiplication table: ";
  
  if (!(std::cin >> rows >> cols))
    {
      rows = distrib(gen);
      cols = rows;
    }
  //std::cout << rows << cols
  //print multiplication table with X rows and Y columns
  for(int i = 0; i <= rows; i++)
    {
      std::cout << '\n';
      for(int j = 0; j <= cols; j++)
	{
	  if(i < 1)
	    { std::cout << j << '\t'; }
	  else if (j < 1)
	    { std::cout << i << " |\t"; }
	  else
	    { std::cout << i*j << '\t'; }
	}
    }

  std::cout << std::endl;
	
  

  
}

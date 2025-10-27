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
      if(i == 1) std::cout << '\n';
      std::cout << '\n';
      for(int j = 0; j <= cols; j++)
	{
	  if(i < 1 && j > 0)
	    { std::cout << "\t" << j; }
	  else if (j < 1)
	    { std::cout << i << "\t"; }
	  else 
	    { std::cout << "\t" << i*j; }
	}
    }

  std::cout << std::endl;
	
  

  
}

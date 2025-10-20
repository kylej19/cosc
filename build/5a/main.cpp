//program
//author
//date
#include <iostream>
#include <string>
#include <random>


int main()
{
  //generate a random number between 1-50 for the computers choice
  
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(1, 50);

  int const COMPUTER_VAL = distrib(gen);
  int user_guess, attempts = 0;
  //std::cout << COMPUTER_VAL << std::endl;

  std::cout << "Welcome to the Guessing Game.\n\nI am picking a number between 1 and 50.\n\nTry to guess the number:";
  std::cin >> user_guess;

  user_guess = static_cast<int>(user_guess);

  while(user_guess != COMPUTER_VAL)
    {
      std::cout << "\n\n[x]\tIncorrect guess.\n\n";
      if(user_guess > COMPUTER_VAL)
	{
	  std::cout << "(Your guess was too high).\n";
	} else
	{
	  std::cout << "(Your guess was too low).\n";
	}
      std::cout << "Guess again: ";
      attempts++;
      std::cin >> user_guess;
    }
  std::cout << "You are correct! The number was " << COMPUTER_VAL
	    << "\n\nIt took you " << attempts << " attempts.\n";



  std::cout << std::endl;
}

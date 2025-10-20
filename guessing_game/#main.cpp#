//program: guessing-game
//author: Kyle Johnson
//date: Oct 11, 2025
#include <iostream>
#include <string>
#include <random>
#include "input_validation.h"


int main()
{
  //create and seed a random number generator for the cpu selection  
  std::random_device rd;
  std::mt19937 gen(rd());
  //a flag for replaying the game
  bool play_again {true};
  char user_choice;
  //variables for storing user guess and keeping track of attempts (as well as the lowest score of games)
  int user_guess, computer_choice, upper_bound, score, best_score = 99;

  std::cout << "\n\nWelcome to the Guessing Game!\n";
  
  upper_bound = get_valid_integer("\nI will pick a number between 1 and any number you choose. Pick the upper bound: ");

  std::uniform_int_distribution<> distrib(1, upper_bound);
  while(play_again)
    {
      score = 1;
      computer_choice = distrib(gen);      
      std::cout << "\nI am thinking of a number! What is it? ";
      std::cin >> user_guess;
      if(std::cin.fail())
	{
	  std::cout << "\n*error* input must be int.\n enter guess: ";
	  std::cin.clear();
	  std::cin.ignore(1000,'\n');
	  continue;
	}
      if(std::cin.peek() != '\n' && std::cin.peek() != EOF)
	{
	  std::cout << "\n*error* invalid input detected. remove any non-integer characters.\n";
	  std::cin.ignore(1000,'\n');
	  continue;
	}
      while(user_guess != computer_choice)
	{
	  std::cout << "\n[x]\tIncorrect guess.\n";
	  if(user_guess > computer_choice)
	    {
	      std::cout << "(Your guess was too high).\n";
	    } else
	    {
	      std::cout << "(Your guess was too low).\n";
	    }
	  std::cout << "Guess again: ";
	  score++;
	  std::cin >> user_guess;
	}
      std::cout << "\nYou are correct! The number was " << computer_choice
		<< "\nIt took you " << score << " attempts.\n";
      
      if(score < best_score)
	{
	  std::cout << "***You set a new best score! " << score << " attempts.***\n";
	  best_score = score;
	}
      
      std::cout << "Play again? [Y/n] ";
      std::cin >> user_choice;
      
      if(user_choice == 'N' || user_choice == 'n') play_again = false;
    }

  std::cout << std::endl;
}

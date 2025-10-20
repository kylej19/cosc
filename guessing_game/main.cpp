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
  int play_again {1};
  //variables for storing user guess and keeping track of attempts (as well as the lowest score of games)
  int user_guess, computer_choice, upper_bound, score, best_score = 99;

  std::cout << "\n*****\t\t*****\nwelcome to the guessing game!\n";
  
  upper_bound = get_valid_integer("\ni will pick a number between 1 and any number you choose. enter the upper bound: ");

  std::uniform_int_distribution<> distrib(1, upper_bound);
  while(play_again)
    {
      score = 1;
      computer_choice = distrib(gen);      
      user_guess = get_valid_integer("\ni have my number. what is your guess? ");
      while(user_guess != computer_choice)
	{
	  std::cout << "\n[x]\tincorrect guess.\n";
	  if(user_guess > computer_choice)
	    {
	      std::cout << user_guess << " is too high.\n";
	    } else
	    {
	      std::cout << user_guess << " is too low.\n";
	    }
	  score++;
	  user_guess = get_valid_integer("guess again: ");
	}
      std::cout << "\nyou are correct! my number was " << computer_choice
		<< "\nit took you " << score << " attempts.\n";
      
      if(score < best_score)
	{
	  std::cout << "\n***you set a new best score!\t" << score << " attempts.***\n";
	  best_score = score;
	}

      play_again = get_valid_integer("\nplay again? 1 for no, any other number for yes: ");
      if(play_again == 1) play_again = 0;
    }

  std::cout << std::endl;
}

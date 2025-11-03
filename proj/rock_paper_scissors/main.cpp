//name: kyle johnson
//section: 014
//Lab 6a: Rock Paper Scissors
//This program plays Rock, Paper, Scissors with the user

#include <iostream>
#include <random>
#include <string>

//function prototypes
int getComputerChoice();
void printMenu();
int chooseWinner(int, int);
std::string displayWordChoice(int);

int main()
{

  int computerChoice, playerChoice, winningPlayer;
  char playAgain;
  do {
    computerChoice = getComputerChoice();
    printMenu();
    std::cout << "What do you choose? ";
    std::cin >> playerChoice;
    while (playerChoice < 1 || playerChoice > 3)
      {
	std::cout << "That was not a valid choice.  Try again." << std::endl;
	printMenu();
	std::cout << "What do you choose? ";
	std::cin >> playerChoice;
      }
    std::cout << std::endl << "You chose: " << displayWordChoice(playerChoice) << std::endl;
    std::cout << "Computer chose: " << displayWordChoice(computerChoice) << std::endl;
    winningPlayer = chooseWinner(playerChoice, computerChoice);
    if (winningPlayer == 1)
      std::cout << "*** You win! ***" << std::endl;
    else if (winningPlayer == 2)
      std::cout << "*** Computer Wins! ***" << std::endl;
    else
      std::cout << "*** It's a tie! ***" << std::endl;
    std::cout << std::endl << "Want to play again? (y/n): ";
    std::cin.ignore();
    std::cin.get(playAgain);
  } while (playAgain == 'Y' || playAgain == 'y');
   return 0;
}


//getComputerChoice returns a random number 1-3 symbolizing the 
//computer choosing rock, paper, or scissors (in that order)
int getComputerChoice()
{
  //random number generator
  std::random_device rd;
  //uses mersenne twister algorithm (i was told it is a good algorithm by gemini)
  std::mt19937 gen(rd());
  //this is what will return the random number, in a range that fits our purposes
  std::uniform_int_distribution<> shoot(1,3);
  int cpu_val = shoot(gen);
  
  return cpu_val;
}

//printMenu prints a menu of options for the user.  Choices are 1-3
//symbolizing choosing rock, paper, or scissors (in that order)
void printMenu()
{
  std::cout << "let's play rock, paper, scissors.\n";
  std::cout << "\nselect option:\n1 - rock\n2 - paper\n3 - scissors\n" << std::endl;
}

//chooseWinner returns a 1 if the user wins, 2 if the Computer wins,
//or 3 if it is a tie.
//To determine a winner:
//rock beats scissors
//paper beats rock
//scissors beats paper

int chooseWinner(int cpu, int player)
{
  if((cpu ==  1 && player == 2) || (cpu == 2 && player == 3) || (cpu == 3 && player == 1))
    return 2;
  else if ((cpu == 1 && player == 3) || (cpu == 2 && player == 1) || (cpu == 3 && player == 2))
    return 1;
  else return 3;
}

//displayWordChoice returns a string with the word Rock, Paper, or Scissors
//based upon the numeric choice passed into the function (1 = Rock, 2 = Paper,
//3 = Scissors)

std::string displayWordChoice(int choice)
{
  if(choice == 1)
    return "rock";
  else if(choice == 2)
    return "paper";
  else if(choice ==3)
    return "scissors";
  else return "invalid option";
}

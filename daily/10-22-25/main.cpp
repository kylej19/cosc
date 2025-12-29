#include <iostream>
#include <random>
#include <string>

int main()
{
  // rand
  std::random_device rd;
  std::mt19937  gen(rd());
  std::uniform_int_distribution<int> distrib(1,100);

  int computer_val = distrib(gen);
  //std::cout << computer_val << '\n';

  // class exercises ...
  std::string user_input {};
  std::string vowells {"aeiou"};
  
  std::cout << "Enter three or more words: ";
  std::getline(std::cin, user_input);
  std::cout << "\n\n---\n\n";

  char spaces = ' ';
  int count_v = 0, count_space = 0;
  
    
  for(int i = 0;i < user_input.length();i++)
    {
      if(user_input[i] == spaces)
	{
	  std::cout << "\n";
	  count_space++;
	}
      else std::cout << user_input[i];
      for(int j = 0;j < vowells.length();j++)
	{
	  if(user_input[i] == vowells[j])
	    {
	      //std::cout << "\nindex " << i << "/" << user_input.length()-1 << ": " << user_input[i];
	      count_v++;
	    }
	}
    }
  std::cout << "\n\n---\tTOTALS\t---\n\n"
	    << "\nwords: " << count_space + 1
	    << "\nvowells: " << count_v 
	    << "\n\n\n" << std::endl;
}

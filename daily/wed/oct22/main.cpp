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

  int count {0};
    
  for(int i = 0;i < user_input.length();i++)
    {
      for(int j = 0;j < vowells.length();j++)
	{
	  if(user_input[i] == vowells[j])
	    {
	      std::cout << "\nindex " << i << "/" << user_input.length()-1 << ": " << user_input[i];
	      count++;
	    }
	}
    }
  std::cout << '\n' << count;
  std::cout << std::endl;
}

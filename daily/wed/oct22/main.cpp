#include <iostream>
#include <random>

int main()
{
  // rand
  std::random_device rd;
  std::mt19937  gen(rd());
  std::uniform_int_distribution<int> distrib(1,100);

  int computer_val = distrib(gen);
  std::cout << computer_val << '\n';

  // class exercises ...

  
  std::cout << std::endl;
}

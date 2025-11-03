#include <iostream>
#include <random>
#include <string>

#include <cstdlib>
#include <ctime>

int main()
{
  // rand
  std::random_device rd;
  std::mt19937  gen(rd());
  std::uniform_int_distribution<int> distrib(1,3);

  std::cout << "running exercise. press [0] to end." << '\n';

  // class exercises ...

  std::srand(std::time(0));

  int user_choice = 1;
  do {

    int cpu_val1 = distrib(gen);
    int cpu_val2 = distrib(gen);
    std::cout << cpu_val1 << '\n' << cpu_val2 << '\n';
    std::cin >> user_choice;

  } while (user_choice);

  
  std::cout << std::endl;
}

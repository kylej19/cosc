#include <print>
#include <random>

int random_number(int, int);

int main()
{
  std::println("The random number is {}.", random_number(0,10));
  return 0;
}

int random_number(int low, int high)
{

  // rand
  std::random_device rd; // seed
  std::mt19937 gen(rd()); // engine
  std::uniform_int_distribution<int> distrib(low, high); // implement

  return distrib(gen);
}  

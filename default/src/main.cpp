#include <iostream>
#include <random>

int main()
{
  // rand
  std::random_device rn_dev; // seed
  std::mt19937  generator(rn_dev()); // engine
  std::uniform_int_distribution<int> distribute(1,100); // implement

  int comp_val = distribute(generator);
  std::cout << "cpu: " << comp_val << '\n';

  // class exercises ...

  
  std::cout << std::endl;
}

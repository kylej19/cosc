#include <iostream>
#include <random>
#include <vector>


int main()
{
  // rand
  std::random_device rn_dev; // seed
  std::mt19937  generator(rn_dev()); // engine
  std::uniform_int_distribution<int> distribute(60,100); // implement

  int comp_val = distribute(generator);
  std::cout << "cpu: " << comp_val << '\n';

  // class exercises ...

  std::vector<int> v (8,0);
  
  for(int i = 0; i <= v.size(); i++) v[i] = distribute(generator);

  for(int i = 0; i <= v.size(); i++)


  std::cout << std::endl;
}

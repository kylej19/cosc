#include <iostream>
#include <random>
#include <string>


void changePin(int& pinNum);

int main()
{

  // class exercises ...

  //overloading functions

  int pin = 1234;

  std::cout << pin << "\n";
  changePin(pin);
  std::cout << pin << "\n";

  return 0;

}

void changePin(int& pin)
{
    // rand
  std::random_device rd;
  std::mt19937  gen(rd());
  std::uniform_int_distribution<int> distrib(1000,9999);
  pin =  distrib(gen);
  
}

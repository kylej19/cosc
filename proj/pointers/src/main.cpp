#include <iostream>
#include <print>
#include <vector>
#include <limits>

int main()
{
  int amount;
  int* ptr = &amount;

  std::print("enter an int:");
  std::cin >> amount;

  while (std::cin.fail())
    {
      std::println("*ERROR* must be integer");
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin >> amount;
    }
  std::cout << "memory address: " << &amount << "\nvalue: " << amount << "\nptr: " << ptr << "\nderef: " << *ptr << "\n";

  return 0;

}

#include <iostream>
#include <iomanip>
#include <random>
#include <string>

int main() {
  //rng
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distrib(0,9);

  int rating = 10;
  std::string name = "nicole";
  char first_initial = 'n';


  for(int i = 0; i < (name.length() - 0);i++) {
    std::cout << name[i] << "\t";
  }
  std::cout << std::endl;
}

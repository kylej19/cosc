#include <iostream>
#include <random>

void doubleGold(int *ptr){
  *ptr *= 2;
}

int main() {
  //rng
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distrib(0,99);

  int gold = distrib(gen);
  std::cout << "gold: " << gold;

  int* map = &gold;
  std::cout << "\nmap: " << map;
  std::cout << "\n*map: " << *map;
  std::cout << "\n{*map = 25;}\n";
  *map = 25;
  std::cout << "\ngold: "<< gold << "\t*map: " << *map;

  int gems[3] = {5,10,15};
  int* bag = gems;

  std::cout << "\n\n*bag: " << *bag;
  std::cout << "\n*bag + 1: " << *(bag + 1);
  std::cout << "\n*bag + 2: " << *(bag + 2);

  doubleGold(map);

  std::cout << "\n\ngold: " << *map;

  std::cout << std::endl;
  //const
  // const int SIZE = 10;
  // const int * const size_ptr = &SIZE;

  // int arr[*size_ptr];

  // for(int i = 0;i < SIZE;i++) {
  //   arr[i] = distrib(gen);
  // }
  // // 1
  // double value = 29.7;
  // double *ptr_a = &value;

  // std::cout << *ptr_a << "\n";

  // //2
  // int set_a[10];
  // *(set_a + 7) = 99;

  // //3
  // const int arr_b[3] = {1,2,3};
  // const int *ptr_b = arr_b;

  // //4
  // int values[20],* iptr = nullptr;
  // iptr = values;
  // *iptr *= 2;

  // //5
  // int x, *ptr_c = nullptr;
  // ptr_c = &x;

  return 0;
}

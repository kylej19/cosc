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
  std::cout << "int gold = distrib(gen);\ngold = " << gold;

  int* map = &gold;
  std::cout << "\n\nint* map = &gold;";
  std::cout << "\nmap = " << map;
  std::cout << "\n*map = " << *map;
  *map = distrib(gen);
  std::cout << "\n\n*map = distrib(gen);";
  std::cout << "\ngold = "<< gold << "   *map = " << *map;
  doubleGold(map);
  std::cout << "\n\ndoubleGold(map);\n" << "gold = " << gold << "   *map = " << *map;

  int gems[3];
  for(int i = 0; i < 3;i++) {
    *(gems + i) = distrib(gen);
  }
  int* bag = gems;

  std::cout << "\n\nint gems[3] = {3 random values};" << "\nint* bag = gems;";
  std::cout << "\ngems[0] = " << gems[0];
  std::cout << "   *(bag + 0) = " << *(bag + 0);
  std::cout << "\ngems[1] = " << gems[1];
  std::cout << "   *(bag + 1) = " << *(bag + 1);
  std::cout << "\ngems[2] = " << gems[2];
  std::cout << "   *(bag + 2) = " << *(bag + 2);

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

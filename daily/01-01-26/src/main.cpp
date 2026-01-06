#include <iostream>
#include "adhoc.h"

int main()
{
  int nums[3];

  for (int& val : nums)
    {
      val = read_number();
    }

  for (int val : nums)
    {
      std::cout << val << std::endl;
    }

  return 0;
}

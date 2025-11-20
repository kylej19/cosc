#include <iostream>
#include <random>

int main()
{
  // int grades[3][4];

  // for(int row = 0; row < 3;row++)
  //   {
  //     std::cout << row+1 << " Student Grades: \n";
  //     for(int col = 0; col < 4; col++)
  // 	{
  // 	  std::cin >> grades[row][col];
  // 	}
  //   }

  // for(int row = 0;row < 3;row++)
  //   {
  //     std::cout << row+1 << " Student Grades: \n";
  //     for(int col = 0; col < 4; col++)
  // 	{
  // 	  std::cout << grades[row][col] << " ";
  // 	}
  //     std::cout << std::endl;
  //   }

  // double highestAverage = 0;

  // for(int row = 0;row < 3;row++)
  //   {
  //     //local variables for each student
  //     double sum = 0,average = 0, count = 0;
      
  //     for(int col = 0;col < 4; col++)
  // 	{
  // 	  count++;
  // 	  sum += grades[row][col];
  // 	}
  //     average = sum / count;

  //     if(average > highestAverage) highestAverage = average;
      
  //     std::cout << row+1 << " student average: " << average;
      
  //     std::cout << "\n\n\n\n" << std::endl;
  //   }

  // int nums[3][3] = { {1, 2, 3}, {-1, -2, -3}, {0, 0, 0} };
  // int sumNums = 0;
  
  // for(int i = 0; i < 3; i++)
  //   {
  //     for(int j = 0; j < 3; j++)
  // 	{
  // 	  sumNums += nums[i][j];
  // 	}
  //   }
  // std::cout << sumNums << std::endl;

  // rand
  std::random_device rd; // seed
  std::mt19937 gen(rd()); // engine
  std::uniform_int_distribution<int> distrib(1,10000); // implement

  int nums[20000];

  std::cout << "\n(";
  for(int i = 0; i < (sizeof(nums)/sizeof(nums[0])); i++)
    {
      nums[i] = distrib(gen);
      std::cout << nums[i] << "\t";
    }

  std::cout << ")\n";



  

  int target = 10000;
  
  int left = 0;
  int right = (sizeof(nums) / sizeof(nums[0])) - 1;
  while (left< right)
    {
      int index_of_mid = left + right / 2;
      int mid_val = nums[index_of_mid];

      if(mid_val == target)
	{
	  std::cout << "found" ;
	  break;
	}
      if(mid_val > target) right=index_of_mid - 1;
      if(mid_val < target) left=index_of_mid + 1;
    }
    
    
}

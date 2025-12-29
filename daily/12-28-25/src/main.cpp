// from the book, "Starting out with C++ from Control Structures through Objects" by Tony Gaddis, 10th Edition
// Ch. 7, Arrays & Vectors -- Checkpoint 7.7 
#include <iostream>

int main()
{
  const int NUM_FISH = 20;
  int fish[NUM_FISH];

  for(int i = 0; i < NUM_FISH; i++)
    {
      // ask for number of fish
      std::cout << "fisherman " << i + 1 <<", how many fish were caught? ";
      // store it in fish[]
      std::cin >> fish[i];
    }
  // sum variable to keep track of the total
  int sum = 0;
  for(int i : fish)
    {
      sum += i;
    }
  // print out results
  std::cout << "total fish caught: " << sum << std::endl;
  return 0;
}

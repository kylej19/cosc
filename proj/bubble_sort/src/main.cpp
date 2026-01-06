#include <iostream>
#include <vector>
#include <print>
#include <fstream>
#include <random>

void bubble_sort(std::vector<std::string>&);

int main()
{
  
  std::vector<std::string> lines;
  std::string word;
  std::ifstream inputFile("data/lines.txt");

  if (inputFile)
    {
      while (inputFile >> word)
	{
	  lines.push_back(word);
	}
      inputFile.close();
    }
  for (std::string word : lines)
    {
      std::println("{}", word);
    }
  bubble_sort(lines);
  for (std::string word : lines)
    {
      std::println("{}", word);
    }
  
  return 0;
}

void bubble_sort(std::vector<std::string>& lines)
{
  int max_element;
  int index;
  int size = lines.size();

  for (max_element = size - 1; max_element > 0; max_element--)
    {
      for (index = 0; index < max_element; index++)
	{
	  if(lines[index] > lines[index + 1])
	    {
	      std::swap(lines[index], lines[index + 1]);
	    }
	}
    }
}

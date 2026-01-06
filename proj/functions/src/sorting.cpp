#include <vector>

void bubble_sort(std::vector<std::string>& arr)
{
  int max_element;
  int index;

  for (max_element = arr.size() - 1; max_element > 0; max_element--)
    {
      for (index = 0; index < max_element; index++)
	{
	  if(arr[index] > arr[index + 1])
	    {
	      std::swap(arr[index], arr[index + 1]);
	    }
	}
    }
}

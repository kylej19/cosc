#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include <iostream>
#include <limits>
#include <string>

/**
 * @brief Reads an integer from standard input, ensuring the input is a valid integer
 * and that no extra characters were left in the buffer.
 * * @param prompt_message The message displayed to the user before reading the input.
 * @return The validated integer value.
 */
int get_valid_integer(const std::string& prompt_message)
{
  int value;

  // loop until valid input is received
  while(true)
    {
      std::cout << prompt_message;

      // attempt to read value
      if(!(std::cin >> value))
	{
	  // check 1: stream failure
	  std::cout << "\n*error* input must be a whole number.\n";
	  std::cin.clear();
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	  continue;
	}
      else if (std::cin.peek() != '\n' && std::cin.peek() != EOF)
	{
	  // check 2: additional characters
	  std::cout << "\n*error* invalid characters detected. ONLY integers allowed.\n";
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	  continue;
	}
      if(value < 1)
	{
	  std::cout << "\n*error* value must be greater than 0.\n";
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	  continue;
	}

      return value;
    }
}

#endif // INPUT_VALIDATION_H

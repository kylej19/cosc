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
int get_valid_integer(const std::string& prompt_message);

#endif // INPUT_VALIDATION_H

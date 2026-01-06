#include "adhoc.h"
#include <iostream>
#include <print>
#include <limits>

int read_number() {
    int value = 0;
    bool is_valid = false;

    while (!is_valid) {
        std::print("enter an int: ");
        if (std::cin >> value) {
            is_valid = true; 
        } else {
	  std::cin.clear();
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	  std::println("Invalid input. Please try again.");
        }
    }
    return value;
}

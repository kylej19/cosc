#include <iostream>
 
int main()
{
    std::cout << "Printable ASCII [32..126]:\n";
    // initializes c = 32 and iterates through all values until c > 126
    for (char c{' '}; c <= '~'; ++c)
      std::cout << c << ((c + 1) % 32 ? ' ' : '\n');
    std::cout << '\n';
}

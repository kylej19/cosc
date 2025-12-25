#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>
#include <print>

// function prototypes
void draw_table();
char random_char(int, int);
void write_file(std::string, int, int, int, int);

int main()
{
  // variables
  std::string filename, file_dir = "data/";
  std::string full_filename;
  int word_length = 0, lines = 0, starting_index = 0, ending_index = 0;

  // main operations
  // prompt for file selection
  std::cout << "Enter in filename to write: ";
  std::cin >> filename;
  full_filename = file_dir + filename;

  // prompt for character selection
  draw_table();
  std::cout << "Enter the bounding indexes for the random character generator: ";
  std::cin >> starting_index >> ending_index;
  // display comfirmation
  std::cout << "Generating characters between " << static_cast<char>(starting_index) << " to " << static_cast<char>(ending_index) << ".";

  std::cout << "\nEnter in word length followed by the number of lines to print: ";
  std::cin >> word_length >> lines;

  write_file(full_filename, word_length, lines, starting_index, ending_index);
  
  return 0;
}
void draw_table()
{
  std::cout << "ASCII TABLE\n";  
  for(char c = ' '; c <= '~'; c++)
    {
      int i = static_cast<int>(c);
      std::cout << std::setw(3) << i << "| \"" << c << "\"" << ((i + 1) % 8 ? ' ' : '\n');
    }
  std::cout << std::endl;
}  
char random_char(int starting_index, int ending_index)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distrib(starting_index, ending_index);
  return static_cast<char>(distrib(gen));
}
void write_file(std::string filename, int cols, int rows, int starting_index, int ending_index)
{
  int total_words = cols * rows;
  std::ofstream output_file(filename);
  for(int i = 0; i < total_words; i++)
    {
      output_file << random_char(starting_index, ending_index) << ((i+1) % cols ? "" : "\n");
    }
  output_file.close();
  std::println("Wrote to {0} lines to file {1}.", rows, filename);
}

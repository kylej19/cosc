#include <iostream>
#include <random>

int main()
{
  // rand
  std::random_device rn_dev; // seed
  std::mt19937  generator(rn_dev()); // engine
  std::uniform_int_distribution<int> distribute(0,7); // implement

  std::string user_query, replay;
  bool flag;

  std::string response[8] = { "\nIt is certain.",
    "\nIt is decidedly so.",
    "\nWithout a doubt.",
    "\nCannot predict now.",
    "\nReply hazy, try again.",
    "\nMy sources say no.",
    "\nOutlook not so good.",
    "\nNot a chance."};

  std::cout << "THE MAGIC 8BALL\n\n";
  std::cout << "seek and you shall find";

  do {
    std::cout << "\nwhat do you seek? ";
    std::cin >> user_query;

    
    std::cout << response[distribute(generator)];
    std::cout << "\n\ndo you have any additional queries? (y/N) ";

    std::cin.ignore();    
    std::cin >> replay;
    if(replay == "y" || replay == "Y" || replay == "yes" || replay == "Yes")
      {
	flag = true;
      }
    else
      {
	flag = false;
      }
  } while (flag);

  std::cout << "\ngoodbye.";
  
  std::cout << std::endl;
}

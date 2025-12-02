#include <iostream>
#include <iomanip>

int main()
{
  // constants
  const double IN_2_CM = 2.54;
  const double FEET_2_IN = 12.00;
  const double CM_2_M = 0.01;

  // variables
  int imperial_ft, imperial_in, total_in;
  double total_cm, metric_m;

  std::cout << "Input (feet, inches): ";
  std::cin >> imperial_ft >> imperial_in;

  total_in = (imperial_ft * FEET_2_IN) + imperial_in;
  
  total_cm = total_in * IN_2_CM;

  metric_m = total_cm * CM_2_M;

  std::cout << std::setprecision(2) << "\n" << metric_m << std::endl;
  
}

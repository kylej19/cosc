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

  // ask user for input and assign it to our variables
  std::cout << "Input height (feet, inches): ";
  std::cin >> imperial_ft >> imperial_in;

  // convert the height(feet, inches) into inches
  total_in = (imperial_ft * FEET_2_IN) + imperial_in;
  // convert inches into centimeters
  total_cm = total_in * IN_2_CM;
  // convert centimeters into meters
  metric_m = total_cm * CM_2_M;

  // output height in meters
  std::cout << std::setprecision(3) << "You are " << metric_m << " meters tall." <<std::endl;
  
}

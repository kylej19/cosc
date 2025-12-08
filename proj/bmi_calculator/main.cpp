#include <iostream>
#include <iomanip>

int main()
{
  // constants
  const double IN_2_CM = 2.54;
  const double FEET_2_IN = 12.00;
  const double CM_2_M = 0.01;
  const double LB_2_KG = 2.2;

  // variables
  int imperial_ft, imperial_in, total_in;
  double total_cm, metric_m, weight_lb, weight_kg, bmi;

  // ask user for input and assign it to our variables
  std::cout << "Input height (feet [SPACE] inches): ";
  std::cin >> imperial_ft >> imperial_in;
  std::cout << "Input weight (lbs.): ";
  std::cin >> weight_lb;

  // convert the height(feet, inches) into inches
  total_in = (imperial_ft * FEET_2_IN) + imperial_in;
  // convert inches into centimeters
  total_cm = total_in * IN_2_CM;
  // convert centimeters into meters
  metric_m = total_cm * CM_2_M;
  // conversion between pounds and kilograms
  weight_kg = weight_lb / LB_2_KG;

  // calculate bmi using metric measurements
  bmi = weight_kg / (metric_m * metric_m);

  // output height in meters
  std::cout << std::setprecision(3) << "You are " << metric_m << " meters tall.";
  std::cout << std::setprecision(4) << "\nYou weigh " << weight_kg << " kilograms.";
  std::cout << std::setprecision(4) << "\nYour BMI is " << bmi;

  // bmi classification
  if(bmi <= 18.5)
    {
      std::cout << ". You are underweight." << std::endl;
    }
  else if(bmi < 25.0)
    {
      std::cout << ". You are at a normal weight." << std::endl;
    }
  else if(bmi < 30.0)
    {
      std::cout << ". You are overweight." << std::endl;
    }
  else if(bmi < 35.0)
    {
      std::cout << ". You are mildly obese." << std::endl;
    }
  else if(bmi < 40)
    {
      std::cout << ". You are obese." << std::endl;
    }
  else std::cout << ". You are morbidly obese." << std::endl;
  
}

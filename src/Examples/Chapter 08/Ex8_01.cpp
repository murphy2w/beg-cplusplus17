// Calculating powers
#include <iostream>
#include <iomanip>

// Function to calculate x to the power n
double power(double x, int n)
{
  double result{ 1.0 };
  if (n >= 0)
  {
    for (int i {1}; i <= n; ++i)
      result *= x;
  }
  else // n < 0
  {
    for (int i {1}; i <= -n; ++i)//-n 大于0
      result /= x;
  }
  return result;
}

int main()
{
  // Calculate powers of 8 from -3 to +3
  for (int i{ -3 }; i <= 3; ++i)
    std::cout << std::setw(10) << power(8.0, i);

  std::cout << std::endl;
}

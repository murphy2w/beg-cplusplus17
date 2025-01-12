// Exercise 5-6. Working with a vector container
#include <iostream>
#include <iomanip>
#include <vector>

int main()
{
  std::cout << "What is the largest number I should check? ";
  unsigned bound {};
  std::cin >> bound;

  std::vector<unsigned> values;
  // Add element values 1 to bound
  for (unsigned i {1}; i <= bound; ++i)
    values.push_back(i);

  size_t count {};                              // Number of output values
  size_t perline {10};                          // Number output perline                 
  for (auto value : values)
  {
    if (value % 7 == 0 || value % 13 == 0) continue;
    std::cout << std::setw(6) << value;
    if (++count % perline == 0) std::cout << "\n";
  }
  std::cout << std::endl;
}
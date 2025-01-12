// Exercising the use of function pointers as callback functions
#include <iostream>
#include <string>
#include "Optimum.h"

// Comparison prototypes:
bool less(const int&, const int&); 
template <typename T> bool greater(const T&, const T&);
bool longer(const std::string&, const std::string&);

int main()
{
  std::vector<int> numbers{ 91, 18, 92, 22, 13, 43 };
  std::cout << "Minimum element: " << *find_optimum(numbers, less) << std::endl;
  std::cout << "Maximum element: " << *find_optimum(numbers, greater<int>) << std::endl;

  std::vector<std::string> names{ "Moe", "Larry", "Shemp", "Curly", "Joe", "Curly Joe" };
  std::cout << "Alphabetically last name: " 
            << *find_optimum(names, greater<std::string>) << std::endl;
  std::cout << "Longest name: " << *find_optimum(names, longer) << std::endl;
}


bool less(const int& one, const int& other) { return one < other; }

template <typename T>
bool greater(const T& one, const T& other) { return one > other; }

bool longer(const std::string& one, const std::string& other)
{
  return one.length() > other.length();
}

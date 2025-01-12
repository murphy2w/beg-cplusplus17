// Using a default capture-by-value clause to access a local variable 
// from within the body of a lambda expression.
#include <iostream>
#include "Optimum.h"

int main()
{
  std::vector<int> numbers{ 91, 18, 92, 22, 13, 43 };

  int number_to_search_for {};
  std::cout << "Please enter a number: ";
  std::cin >> number_to_search_for;

  auto nearer {
    [=](int x, int y) {
      return std::abs(x - number_to_search_for) < std::abs(y - number_to_search_for);
    }
  };
  std::cout << "The number nearest to " << number_to_search_for << " is "
            << *find_optimum(numbers, nearer) << std::endl;
}

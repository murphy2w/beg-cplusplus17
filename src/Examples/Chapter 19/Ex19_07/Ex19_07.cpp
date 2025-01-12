// Iterating over the elements of a list<>
#include <iostream>
#include <list>

int main()
{
  std::cout << "Enter a sequence of positive numbers, "
            << "terminated by a negative number: "; 

  std::list<unsigned> numbers;
  
  while (true)
  {
    signed number{-1};
    std::cin >> number;
    if (number < 0) break;
    numbers.push_back(static_cast<unsigned>(number));
  }

  std::cout << "You entered the following numbers: ";
  for (auto iter {numbers.begin()}; iter != numbers.end(); ++iter)
  {
    std::cout << *iter << ' ';
  }
  std::cout << std::endl;
}

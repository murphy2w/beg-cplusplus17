// Using the std::function<> template
#include <iostream>
#include <functional>
#include <cmath>            // for std::abs()

// A global less() function
bool less(int x, int y) { return x < y; }

int main()
{
  int a{ 18 }, b{ 8 };  
  std::cout << std::boolalpha;    // Print true/false rather than 1/0

  std::function<bool(int,int)> compare;
  
  compare = less;                           // store a function pointer into compare
  std::cout << a << " < " << b << ": " << compare(a, b) << std::endl;
  
  compare = std::greater<>{};               // store a function object into compare
  std::cout << a << " > " << b << ": " << compare(a, b) << std::endl;
  
  int n{ 10 };                              // store a lambda closure into compare
  compare = [n](int x, int y) { return std::abs(x - n) < std::abs(y - n); };
  std::cout << a << " nearer to " << n << " than " << b << ": " << compare(a, b);

  // Check whether a function<> object is tied to an actual function
  std::function<void(int&&)> empty;
  if (empty)                        // Or, equivalently: �if (empty != nullptr)�
  {
    std::cout << "Calling a default-constructed std::function<>?" << std::endl;
    empty(std::move(a));
  }
}

// Exercise 6-2. Traversing arrays using pointer arithmetics
// An exercise to further deepen your understanding of the relation 
// between pointers, pointer arithmetic, and arrays.

#include <iostream>
#include <iomanip>

int main()
{
  const size_t n {50};
  size_t odds[n];
  for (size_t i {}; i < n; ++i)
    odds[i] = i + 1;

  const size_t perline {10};
  std::cout << "The numbers are:\n";
  
  size_t* traversal_pointer = odds;
  for (size_t i {}; i < n; ++i)
  {
    std::cout << std::setw(5) << *traversal_pointer++;
    if ((i + 1) % perline == 0)                           // Uses the loop counter to decide when a newline is required
      std::cout << std::endl;
  }

  std::cout << "\nIn reverse order the numbers are:\n";
  for (size_t i {}; i < n; ++i)                           // No need to reverse the manipulation of the loop counter now
  {
    std::cout << std::setw(5) << *(--traversal_pointer);  // Use the pre-decrement operator to make sure the pointer is decremented
    if ((i + 1) % perline == 0)                           // before it is dereferenced (at the start of this loop, 
      std::cout << std::endl;                             // the pointer points one passed the last element of the odds array)
  }
}
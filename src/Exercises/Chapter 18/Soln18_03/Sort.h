// Sort.h

#ifndef SORT_H
#define SORT_H

#include <cstddef>    // for size_t
#include <utility>    // for std::swap()
#include <vector>

// Swap two vector elements
template<typename T>
inline void swap(std::vector<T>& data, size_t first, size_t second)
{
  std::swap(data[first], data[second]);
}

template<typename T, typename Compare>
void bubbleSort(std::vector<T>& data, Compare compare)
{
  if (data.empty())
    return;

  while (true)
  {
    bool swapped{ false };          // becomes true when not all values are in order
    for (size_t i {}; i < data.size() - 1; ++i)
    {
      if (compare(data[i+1], data[i]))  // Out of order so swap them
      {
        swap(data, i, i+1);
        swapped = true;
      }
    }
	
    if (!swapped)                   // If there were no swaps
      break;                        // ...they are in order...
  }                                 // ...otherwise, go round again.
}	

// The top level quicksort() template with one parameter calls the quicksort() template with three parameters

// Sort a range of vector elements
template<typename T, typename Compare>
void quicksort(std::vector<T>& data, Compare compare, size_t start, size_t end)
{
  // Start index must be less than end index for 2 or more elements
  if (!(start < end))
    return;

  // Choose middle value to partition set
  swap(data, start, (start + end) / 2);       // Swap middle value with start
 
  // Check data against chosen value
  size_t current{ start };                    // The index of the last element less than the chosen element (after partitioning)
  for (size_t i{ start + 1 }; i <= end; ++i)
  {
    if (compare(data[i], data[start]))        // Is value less than chosen word?
      swap(data, ++current, i);               // Yes, so swap to the left
  }

  swap(data, start, current);                 // Swap the chosen value with last in

  if (current) quicksort(data, compare, start, current - 1);  // Sort left subset (if exists)
  quicksort(data, compare, current + 1, end);                 // Sort right subset (if exists)
}

// Sort all vector elements using quicksort
template<typename T, typename Compare>
inline void quicksort(std::vector<T>& values, Compare compare)
{
  if (!values.empty())
    quicksort(values, compare, 0, values.size() - 1);
}

#endif // SORT_H
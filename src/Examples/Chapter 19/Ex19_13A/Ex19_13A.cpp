// Extracting all odd numbers using std::back_inserter().
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>	           // For std::back_inserter()

std::set<int> fillSet_1_to_N(size_t N);      // Fill a set with 1, 2, ..., N
void printVector(const std::vector<int>& v); // Print the contents of a vector to std::cout

int main()
{
  const size_t num_numbers{ 20 };

  const auto numbers = fillSet_1_to_N(num_numbers);

  std::vector<int> odd_numbers;
  std::copy_if(begin(numbers), end(numbers), std::back_inserter(odd_numbers),
    [](int n) { return n % 2 == 1; });

  printVector(odd_numbers);
}

std::set<int> fillSet_1_to_N(size_t N)   // Fill a set with 1, 2, ..., N
{
  std::set<int> numbers;
  for (int i{ 1 }; i <= N; ++i)
    numbers.insert(i);
  return numbers;
}

void printVector(const std::vector<int>& v)
{
  for (auto i : v) std::cout << i << ' ';
  std::cout << std::endl;
}
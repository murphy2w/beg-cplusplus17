// Exercise 11-7
// Create a doubly-linked list of Packages
/*
   To show reverse iteration, we've modified findSmallestBox() to iterate in reverse order
 */
#include <cstdlib>                     // For random number generation
#include <ctime>                       // For the std::time() function
#include "Truckload.h"

SharedBox findLargestBox(const Truckload& truckload);
SharedBox findSmallestBox(const Truckload& truckload);
void addRandomBoxes(Truckload& truckload, size_t num);
void addRandomBoxes(std::vector<SharedBox>& vector, size_t num);

int main()  
{
  std::srand((unsigned)std::time(0));  // Initialize the random number generator

  Truckload load1;                     // Create an empty list
  addRandomBoxes(load1, 12);

  std::cout << "The first list:\n";
  load1.listBoxes();
  std::cout << "In reversed order, this becomes:\n";
  load1.listBoxesReversed();

  // Find the largest Box in the list
  SharedBox largestBox{findLargestBox(load1)};

  std::cout << "\nThe largest box in the first list is ";
  largestBox->listBox();
  std::cout << std::endl;
  load1.removeBox(largestBox);
  std::cout << "\nAfter deleting the largest box, the list contains:\n";
  load1.listBoxes();

  std::vector<SharedBox> boxes;        // Array of Box objects
  addRandomBoxes(boxes, 20);

  Truckload load2{boxes};
  std::cout << "\nThe second list:\n";
  load2.listBoxes();

  std::cout << "\nThe smallest box in the second list is ";
  findSmallestBox(load2)->listBox();
  std::cout << std::endl;
}

SharedBox findLargestBox(const Truckload& truckload)
{
  auto iterator = truckload.getIterator();        // type of iterator is Truckload::Iterator
  SharedBox largestBox{ iterator.getFirstBox() };

  SharedBox nextBox{ iterator.getNextBox() };
  while (nextBox)
  {
    if (nextBox->compare(*largestBox) > 0)
      largestBox = nextBox;
    nextBox = iterator.getNextBox();
  }

  return largestBox;
}

SharedBox findSmallestBox(const Truckload& truckload)
{
  auto iterator = truckload.getIterator();        // type of iterator is Truckload::Iterator
  SharedBox smallestBox{ iterator.getLastBox() };

  SharedBox previousBox{ iterator.getPreviousBox() };
  while (previousBox)
  {
    if (previousBox->compare(*smallestBox) < 0)
      smallestBox = previousBox;
    previousBox = iterator.getPreviousBox();
  }

  return smallestBox;
}

// Function to generate a random integer 1 to count
inline double random(size_t count)
{
  return 1.0 + rand() / (RAND_MAX / count + 1);
}
// Function to generate a Box with random dimensions
inline SharedBox randomBox()
{
  const size_t dimLimit {99};          // Upper limit on Box dimensions
  return std::make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit));
}

void addRandomBoxes(Truckload& truckload, size_t boxCount)
{
  for (size_t i {} ; i < boxCount ; ++i)
    truckload.addBox(randomBox());
}

void addRandomBoxes(std::vector<SharedBox>& boxes, size_t nBoxes)
{
  for (size_t i {} ; i < nBoxes ; ++i)
    boxes.push_back(randomBox());
}
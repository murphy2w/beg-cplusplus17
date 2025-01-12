#include "Truckload.h"

// Constructor
Truckload::Truckload(const std::vector<SharedBox>& boxes)
{
  for (auto pBox : boxes)
  {
    addBox(pBox);
  }
}

// Output all Box objects in the list
void Truckload::listBoxes() const
{
  const size_t boxesPerLine = 5;
  size_t count {};  
  for (Package* package{pHead}; package; package = package->pNext)
  {
    package->pBox->listBox();
    if (! (++count % boxesPerLine)) std::cout << std::endl;
  }
  if (count % boxesPerLine) std::cout << std::endl;
}

// Get the first Box
SharedBox Truckload::Iterator::getFirstBox()
{
  // Return pHead's box (or nullptr if the list is empty)
  pCurrent = pHead;
  return pCurrent? pCurrent->pBox : nullptr;     
}

// Get the next Box
SharedBox Truckload::Iterator::getNextBox()    
{
  if (!pCurrent)                                   // If there's no current...
    return getFirstBox();                          // ...return the 1st Box

  pCurrent = pCurrent->pNext;                      // Move to the next package
  
  return pCurrent? pCurrent->pBox : nullptr;       // Return its box (or nullptr...).
}

// Add a Box to the list
void Truckload::addBox(SharedBox pBox)
{
  auto pPackage = new Package{pBox};       // Create a new Package

  if (pTail)                               // Check list is not empty
    pTail->pNext = pPackage;               // Add the  new  object to the tail
  else                                     // List is empty
    pHead = pPackage;                      // so new object is the head

  pTail = pPackage;                        // Store its address as tail
}

// Find the Package containing pBox and delete it from the list
bool Truckload::removeBox(SharedBox boxToRemove)
{
  Package* previous {nullptr};      // no previous yet
  Package* current {pHead};         // initialize current to the head of the list
  while (current)
  {
    if (current->pBox == boxToRemove)      // We found the Box!
    {
      if (previous)                            // If there is a previous Package...
      {
        previous->pNext = current->pNext;      // ...make it point to the next Package 
      }
      else
      {                                        // If there is no previous, we are removing the 
        pHead = current->pNext;                // first Package in the list, so update pHead
      }
      
      current->pNext = nullptr;                // Disconnect the current Package from the list
      delete current;                          // and delete it
      
      return true;                             // Return true: we found and removed the box
    }
                                               // Move both pointers along (mind the order!)
    previous = current;                        //  - first current becomes the new previous 
    current = current->pNext;                  //  - then move current along to the next Package
  }

  return false;                                // Return false: boxToRemove was not found
}

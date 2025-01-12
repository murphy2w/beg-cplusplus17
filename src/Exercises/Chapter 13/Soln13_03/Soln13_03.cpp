// Exercise 13-3 By addng a few lines to the test program, we can see the difference 
// between the calls to the base class and derived class who() functions. 

#include <iostream>
#include "Animals.h"

int main()
{
  Lion myLion{"Leo", 400};
  Aardvark myAardvark{"Algernon", 50};
  std::cout << "Calling derived versions of who():\n";
  myLion.who();
  myAardvark.who();

  std::cout << "\nCalling base versions of who():\n";
  myLion.Animal::who();
  myAardvark.Animal::who();
}
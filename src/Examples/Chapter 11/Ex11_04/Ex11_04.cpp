// Adding public getters and setters for private member variables
#include <iostream>
#include "Box.h"

int main()
{
  Box myBox {3.0, 4.0, 5.0};
  std::cout << "myBox dimensions are " << myBox.getLength() 
            << " by " << myBox.getWidth() 
            << " by " << myBox.getHeight() << std::endl;

  myBox.setLength(-20.0);		// Ignored!
  myBox.setWidth(40.0);
  myBox.setHeight(10.0);
  std::cout << "myBox dimensions are now " << myBox.getLength() // 3 (unchanged)
            << " by " << myBox.getWidth()                       // by 40
            << " by " << myBox.getHeight() << std::endl;        // by 10
}

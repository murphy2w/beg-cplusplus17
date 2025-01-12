// Exercise 14-6 Exercising Shape classes
#include "Shapes.h"
#include <iostream>
#include <vector>

double calculateSumAreas(const std::vector<Shape*>& shapes);
double calculateSumPerimeters(const std::vector<Shape*>& shapes);
void printSums(const std::vector<Shape*>& shapes);

int main() 
{
  Circle c1{Point{1, 1}, 1};
  Circle c2{Point{2, 2}, 2};
  Circle c3{Point{3, 3}, 3};
  Rectangle r1{Point{4, 5}, 4, 5};
  Rectangle r2{Point{6, 7}, 6, 7};
  Rectangle r3{Point{8, 9}, 8, 9};
  
  std::vector<Shape*> shapes{ &c1, &r1, &r2, &c2, &c3, &r3 };
  
  printSums(shapes);
  
  for (auto* shape : shapes) shape->scale(1.5);
  std::cout << std::endl;
  
  printSums(shapes);
}

double calculateSumAreas(const std::vector<Shape*>& shapes)
{
  double sum {};
  for (auto* shape : shapes)
  {
    sum += shape->area();
  }
  return sum;
}

double calculateSumPerimeters(const std::vector<Shape*>& shapes)
{
  double sum {};
  for (auto* shape : shapes)
  {
    sum += shape->perimeter();
  }
  return sum;
}

void printSums(const std::vector<Shape*>& shapes)
{
  std::cout << "Sum of areas: " << calculateSumAreas(shapes) << std::endl;
  std::cout << "Sum of perimeters: " << calculateSumPerimeters(shapes) << std::endl;
}
// Exercise 10-3 Using namespaces
// We have seven files in all. 
// The file main.cpp only needs to #include two of our three new header files,
// since all it does is call the functions print_this() and print_that():

#include "printthis.h"
#include "printthat.h"
#include "print.h"
#include <iostream>

int main()
{
  print_this("This is a test string using print_this().");
  print_that("This is a test string using print_that().");
}
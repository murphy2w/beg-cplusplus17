// Exercise 10-1 Using multiple files and preprocessor directives.
// We have seven files in all. 
// The file printthat.h contains the prototype for the function print_that().
#ifndef PRINTTHAT_H
#define PRINTTHAT_H

#include <string_view>

// Function prototype
void print_that(std::string_view s);

#endif
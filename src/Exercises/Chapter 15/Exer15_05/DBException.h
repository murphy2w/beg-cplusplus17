// Exercise 15-5  DBException.h
// A simple C++ exception type

#ifndef DB_EXCEPTION_H
#define DB_EXCEPTION_H

#include <stdexcept>

class DataBaseException : public std::runtime_error
{
public:
  using std::runtime_error::runtime_error;  // Inherit constructor
};

#endif
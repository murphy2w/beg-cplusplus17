// Exercise 15-4  DomainExceptions.h
// Definitions of various domain exception classes
/*
	std::domain_error is one of the exception types defined by
	the Standard Libray. It is intended to be used mostly inside
	mathematical functions in case an argument is provided in which
	the function is not defined (for instance, should a regular 
	square root function be called with a negative number)
*/

#ifndef DOMAINEXCEPTIONS_H
#define DOMAINEXCEPTIONS_H
#include <stdexcept>
#include <string>

class NotANumber : public std::domain_error
{
public:
  NotANumber(const std::string& nan) 
    : std::domain_error{"Not a number: " + nan} 
  {}
};

class NegativeNumber : public std::domain_error
{
public:
  NegativeNumber(int number) 
    : std::domain_error{"A negative number was entered: " + std::to_string(number)}
  {}
};

class OddNumber : public std::domain_error
{
public:
  OddNumber(int number) 
    : std::domain_error{"An odd number was entered: " + std::to_string(number)}
  {}
};

#endif //DOMAINEXCEPTIONS_H
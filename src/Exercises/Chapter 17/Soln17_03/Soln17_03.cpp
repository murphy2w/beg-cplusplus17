// Exercise 17-3
/* Below is the same test program as used in Exercise 15-5, 
   with some additional commented lines to show that the RAII objects cannot be copied.
*/

#include <iostream>
#include <vector>

#include "DB.h"
#include "DBException.h"
#include "Customer.h"
#include "DB_RAII.h"

void verifyCustomerFields(DB_QUERY_RESULT* result);           // Sanity check on the number of fields returned by our query
std::vector<Customer> readCustomers(DB_QUERY_RESULT* result); // Convert the DB result to a series of C++ objects
void print(std::ostream& stream, const Customer& customer);   // Print a given customer to a given output stream

std::ostream& getOutputStream()
{
  return std::cout;
}

int main()
{
  DBConnectionRAII connection{ db_connect() };
  /*
    DBConnectionRAII copy{ connection };  // Will not compile (copy constructor is deleted)
  
    DBConnectionRAII otherConnection{ db_connect() };
	otherConnection = connection;         // Will not compile (copy assignment operator is deleted)
  */
  try
  {
    DBQueryResultRAII result{ db_query(connection, "SELECT * FROM CUSTOMER_TABEL") };
    if (!result)
    {
      throw DataBaseException{"Query failed"};
    }
	
  /*
    DBQueryResultRAII copy{ result };    // Will not compile (copy constructor is deleted)
  
    DBQueryResultRAII otherResult{ db_query(connection, "SELECT * FROM CUSTOMER_TABEL") };
    otherResult = result;                // Will not compile (copy assignment operator is deleted)
  */
  
    std::vector<Customer> customers{ readCustomers(result) };
  
  if (customers.empty())
  {
    std::cerr << "No customers found?" << std::endl;
    return 2;
  }
    
  for (auto& customer : customers)
  {
     print(std::cout, customer);
  }
  }
  catch (std::exception& caught)
  {
    std::cerr << caught.what() << std::endl;
    return 1;
  }
}

std::vector<Customer> readCustomers(DB_QUERY_RESULT* result)
{
  // Sanity check 
  // (if the number of fields does not match 5, 
  // the code below would crash!)
  verifyCustomerFields(result);
   
  std::vector<Customer> customers;
  
  auto row{ db_fetch_row(result) };
  while (row)
  {
    customers.push_back(Customer{
      row[0],            // Surname
      row[1],            // Name
      row[2],            // Street
      std::stoi(row[3]), // Street number
      row[4]             // City
    });
    
    row = db_fetch_row(result);
  }
  
  return customers;
}

void verifyCustomerFields(DB_QUERY_RESULT* result)
{
  int numFields{ db_num_fields(result) };
  if (numFields < 0)
  {
    throw DataBaseException{"db_num_fields() failed"};
  }
  if (numFields != 5)
  {
    throw DataBaseException{"Unexpected number of fields: " + std::to_string(numFields)};
  }
}

void print(std::ostream& stream, const Customer& customer)
{
  stream << customer.ToString() << std::endl;
  if (std::cout.fail())
  {
    std::cout.clear();
    throw std::runtime_error("Failed to output customer");
  }
}

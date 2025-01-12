// Exercise 15-5
/* Creating RAII classes to manage resource handles returned by a C interface
   Remember: RAII is not just for dynamic memory: every resource should be managed by an object!
   
   Leaks in the original code:
   - The database connection was not disconnected if an exception occurred indirectly 
     in the main try-catch block. For the DataBaseException thrown in the block itself
     if db_query(), the connection was correctly disconnected. Possible other exceptions also include:
      a) verifyCustomerFields() discovers a problem. This verification step may've been added later
       by someone trying to make the program more robuust, but not familiar enough with the surrounding program...
      b) std::stoi() throws std::invalid_argument because an empty string was passed, 
       or a string that does not start with a number
      c) Customer::ToString() throws std::bad_alloc because memory allocation failed for the new string
	  d) If the output stream used fails for whatever reason, a std::runtime_exception occurs.
       While for std::cout this is less likely, perhaps the program is changed later to output
       to some other stream that writes to a GUI element or a file. These might fail...
   - The memory leaks for the query result are analogous
   - If no customers are found, someone decided to add an extra return statement. This again leaks all resources...
   
   Bottom line: the larger the program becomes, the more resources there are to keep track of,
   and at the same time the more exceptions and return statements there appear.
   Moreover, in real life often many different people collaborate on the same code,
   often less familiar with the original program and the resources it uses.
   It is just too easy to forget one case, and introdue a leak. 
   Even the most disciplined developer will make mistakes this way---believe us!
   Hence: always use some form of RAII to manage resources!
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
  try
  {
    DBQueryResultRAII result{ db_query(connection, "SELECT * FROM CUSTOMER_TABEL") };
    if (!result)
    {
      throw DataBaseException{"Query failed"};
    }
  
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

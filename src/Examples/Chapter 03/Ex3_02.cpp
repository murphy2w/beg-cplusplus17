// Operations with enumerations
#include <iostream>
#include <iomanip>

int main()
{
  enum class Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
  Day yesterday{ Day::Monday }, today{ Day::Tuesday }, tomorrow{ Day::Wednesday };
  const Day poets_day{ Day::Friday };

  enum class Punctuation : char { Comma = ',', Exclamation = '!', Question = '?' };
  Punctuation ch{ Punctuation::Comma };

  // enum class temp : double { M = "12.3", H = "12.1"};

  std::cout << "yesterday's value is " << static_cast<int>(yesterday)
    << static_cast<char>(ch) << " but poets_day's is " << static_cast<int>(poets_day)
    << static_cast<char>(Punctuation::Exclamation) << std::endl;

  today = Day::Thursday;                    // Assign new ...
  ch = Punctuation::Question;               // ... enumerator values
  tomorrow = poets_day;                     // Copy enumerator value

  std::cout << "Is today's value(" << static_cast<int>(today)
            << ") the same as poets_day(" << static_cast<int>(poets_day)
            << ')' << static_cast<char>(ch) << std::endl;

  ch = Punctuation::Question;              // Uncomment ...
  tomorrow =Day::Friday;          // ... any of these ...
  today = Day::Saturday;                  // ... for an error. 
}
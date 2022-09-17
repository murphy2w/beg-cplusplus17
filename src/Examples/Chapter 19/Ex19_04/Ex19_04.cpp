// Basic use of std::map<>
#include <map>
#include <iostream>
#include <string>

int main()
{
  std::map<std::string, unsigned long long> phone_book;
  phone_book["Donald Trump"] = 202'456'1111;
  phone_book["Melania Trump"] = 202'456'1111;
  phone_book["Francis"] = 39'06'6982;
  phone_book["Elizabeth"] = 44'020'7930'4832;

  std::cout << "The president's number is " << phone_book["Donald Trump"] << std::endl;

  for (const auto&[name, number] : phone_book)
    std::cout << name << " can be reached at " << number << std::endl;

  for (const auto&item : phone_book)
  std::cout << item.first << " can be reached at " << item.second << std::endl;

  std::map<std::string, int> map{};
  map["hello"] = 1;
  for(auto &item : map){
    std::cout<<item.first<<":"<<item.second<<std::endl;
  }
}

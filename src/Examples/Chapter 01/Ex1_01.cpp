// A complete C++ program
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
void memory_dump(const void *ptr, int len);
int main()
{
  int answer {42};              // Defines answer with value 42

  std::cout << "The answer to life, the universe, and everything is "
            << answer
            << std::endl;
            string s = "abcd";
            cout << "s.size=" << s.size() <<endl;
            cout << "s.data length" << s.data() <<endl;
            // memory_dump(s.data(), s.size()+2);
  
  string su8 = u8"这是什么?。";
  cout << "su8=" << su8 << ", length=" << su8.size() <<endl;

  double d = 100.8;
  stringstream ss2;
  ss2 << 100.9 << 20 << d;
  cout << ss2.str() << endl;

  return 0;
}

void memory_dump(const void *ptr, int len) {
    int i;

    for (i = 0; i < len; i++) {
        if (i % 8 == 0 && i != 0)
            printf(" ");
        if (i % 16 == 0 && i != 0)
            printf("\n");
        printf("%02x ", *((uint8_t *)ptr + i));
    }
    printf("\n");
}
#include "m_String.h"

/*
 * Operators: +, ==, >=, <=
 * Methods: construct("string"), 
 * IO: stdin, stdout
 */


int main() {
  m_String str;
  m_String str1;
  std::cin >> str >> str1;
  //(str==str1) ? std::cout << "OK\n" : std::cout << "FAIL\n";
  auto answer = str + str1;
  std::cout << answer;
  return 0;
}
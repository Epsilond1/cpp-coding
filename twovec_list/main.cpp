#include "classes.h"

int main() {
  Stack s1 = Stack();

  s1.push(5);
  s1.push(3);
  s1.pop();
  s1.push(-5);
  s1.pop();
  s1.pop();
  s1.push(25);

  s1.top();
  std :: cout << "\n" << s1.len();
  return 0;
}
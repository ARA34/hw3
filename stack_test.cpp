#include <iostream>
#include "stack.h"

int main() {
  // create a stack, do some operations on it
  Stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  // s.insert(s.begin(), 0); // Uh oh — this breaks stack order rules!
  std::cout << s.top() << std::endl;
  s.pop();
  std::cout << s.top() << std::endl;

  return 0;
}
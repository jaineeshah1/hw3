#include <iostream>
#include <fstream>
#include <functional>
#include "stack.h"
using namespace std;

int main(int argc, char* argv[])
{
  Stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.pop();
  std::cout << stack.top() << std::endl;
  std::cout << stack.empty() << std::endl;
  stack.push(3);
  std::cout << stack.size() << std::endl;
  std::cout << stack.top() << std::endl;
}
#include <iostream>
#include <string>
#include "src/where.hpp"

int main() {
  std::string example = "This is something unique, check tests for example outputs";
  std::cout << "For the string: " << example << "\nthe letter f is in index number " << find(example, 'f');
}

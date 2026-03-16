#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

#include "src/raining.hpp"
//using char star instead of c++ strings
int main() {
  std::vector<char*> business;
  char input[256];
  char next[10];

  std::cout << "Welcome to the Business Sorting Program!\n\n";
  while (true) {
    std::cout << "Please enter the name of a business:  ";
    std::cin.getline(input, 256);

    char* name = new char[std::strlen(input) + 1];
    std::strcpy(name, input);
    business.push_back(name);

    // sort using C-string comparison
    std::sort(business.begin(), business.end(),
              [](const char* a, const char* b) {
                  return std::strcmp(a, b) < 0;
              });

    display(business);

    std::cout << "\nAnother business?  ";
    std::cin.getline(next, 10);
    if (!(std::strcmp(next, "y") == 0 ||
          std::strcmp(next, "Y") == 0 ||
          std::strcmp(next, "yes") == 0 ||
          std::strcmp(next, "Yes") == 0)) {
      break;
          }
    std::cout << "\n";
  }

  for (char* b : business) {
    delete[] b;
  }

  std::cout << "\nThank you for using the Business Sorting Program!\n";
  return 0;
}
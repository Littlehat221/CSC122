#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "src/raining.hpp"

int main() {
  std::string input;
  std::vector<std::string> business;
  std::string next = "no";

  std::cout << "Welcome to the Business Sorting Program!\n\n";
  while (true) {
    std::cout << "Please enter the name of a business:  ";
    std::getline(std::cin, input);

    business.push_back(input);
    std::sort(business.begin(), business.end());

    display(business);

    std::cout << "\nAnother business?  ";
    std::getline(std::cin, next);
    if (!(next == "y" || next == "Y" || next == "yes" || next == "Yes")) {
      break;
    }
    std::cout << "\n";
  }
  std::cout << "\nThank you for using the Business Sorting Program!\n";
  return 0;
}

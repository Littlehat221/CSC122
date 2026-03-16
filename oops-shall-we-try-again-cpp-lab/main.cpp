#include <iostream>
#include <string>

#include "src/oops.hpp"

int main() {
  int chosen;
  std::string prompt = "Please enter a value from 1-100 inclusive";
  std::string error = "Your value is invalid";

  int thingy = 100;
  chosen = oops(1,100,prompt, error, &thingy);

  std::cout << "The value chosen by the user is " << chosen << std::endl;
}

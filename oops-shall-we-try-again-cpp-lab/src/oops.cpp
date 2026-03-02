#include <string>
#include <iostream>
#include <limits>

int oops(int lower, int upper, std::string prompt, std::string error) {
   int number;

   std::cout << prompt << std::endl;

   while (!(std::cin >> number) || number < lower || number > upper) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      std::cout << error << std::endl;
      std::cout << prompt << std::endl;
   }

   return number;
}

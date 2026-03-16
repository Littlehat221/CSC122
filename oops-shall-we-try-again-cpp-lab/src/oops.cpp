#include <string>
#include <iostream>
#include <limits>
#include <stdexcept>

int oops(int lower, int upper, std::string prompt, std::string error, const int* defaultValue) {
   std::string fullPrompt = prompt;
   if (defaultValue) {
      fullPrompt += " Enter \"default\" to use the default value of " + std::to_string(*defaultValue) + ".";
   }
   fullPrompt += " Enter \"exit\" to leave the menu.";

   while (true) {
      std::cout << fullPrompt << std::endl;
      std::string line;
      std::getline(std::cin, line);

      if (std::cin.fail()) {
         throw std::runtime_error("Input error");
      }

      if (line == "exit") {
         throw std::runtime_error("User aborted");
      }

      if (defaultValue && line == "default") {
         return *defaultValue;
      }

      try {
         size_t pos;
         int number = std::stoi(line, &pos);
         if (pos != line.length()) {
            throw std::invalid_argument("trailing characters");
         }
         if (number >= lower && number <= upper) {
            return number;
         } else {
            std::cout << error << std::endl;
         }
      } catch (const std::exception&) {
         std::cout << error << std::endl;
      }
   }
}


#include <string>
#include <vector>
#include "prime.hpp"
#include <iostream>
#include <limits>

std::vector<int> Factorizer::primeFactors(int number)
{
   std::vector<int> factors;

   if (number <= 1)
      return factors;

   int divider = 2;

   while (number > 1)
   {
      while (number % divider == 0)
      {
         factors.push_back(divider);
         number = number / divider;
      }
      divider++;
   }

   return factors;
}

int getNumber() {
   int number;
   std::cout << "Type and enter a number" << std::endl;

   while (!(std::cin >> number)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      std::cout << "That is not a number" << std::endl;
      std::cout << "Type and enter a number" << std::endl;
   }
   return number;
}
void printFactors(std::vector<int> factors) {
   std::cout << "[";
   for (int i = 0; i < factors.size(); i++)
   {
      std::cout << factors[i];
      if (i < factors.size() - 1)
         std::cout << ", ";
   }
   std::cout << "]";
}
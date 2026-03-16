#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <limits>
#include "prime.hpp"

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

bool Factorizer::isPrime(int number)
{
    if (number <= 1) return false;
    std::vector<int> factors = primeFactors(number);
    return factors.size() == 1 && factors[0] == number;
}

bool Factorizer::isComposite(int number)
{
    return number > 1 && !isPrime(number);
}

std::string Factorizer::reduce(int numerator, int denominator)
{
    if (denominator == 0) return "undefined";
    if (numerator == 0) return "0";

    std::vector<int> numFactors = primeFactors(numerator);
    std::vector<int> denFactors = primeFactors(denominator);

    std::map<int, int> numCount, denCount;
    for (int f : numFactors) numCount[f]++;
    for (int f : denFactors) denCount[f]++;

    // Cancel common factors
    for (auto& pair : numCount) {
        int factor = pair.first;
        if (denCount.count(factor)) {
            int common = std::min(pair.second, denCount[factor]);
            pair.second -= common;
            denCount[factor] -= common;
        }
    }

    int reducedNum = 1;
    for (const auto& pair : numCount) {
        for (int i = 0; i < pair.second; ++i) {
            reducedNum *= pair.first;
        }
    }

    int reducedDen = 1;
    for (const auto& pair : denCount) {
        for (int i = 0; i < pair.second; ++i) {
            reducedDen *= pair.first;
        }
    }

    if (reducedDen == 1) {
        return std::to_string(reducedNum);
    } else {
        return std::to_string(reducedNum) + "/" + std::to_string(reducedDen);
    }
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
#include <iostream>

#include "src/prime.hpp"

int main() {
    Factorizer object;
    printFactors(object.primeFactors(getNumber()));

    //add on one,two
    int checkNum;
    std::cout << "\nAdd on one, two (is it prime or composite?)\nType and enter a number";
    std::cin >> checkNum;

    if (object.isPrime(checkNum)) {
        std::cout << checkNum << " is prime." << std::endl;
    } else if (object.isComposite(checkNum)) {
        std::cout << checkNum << " is composite." << std::endl;
    } else {
        std::cout << checkNum << " is neither prime nor composite (it is 0 or 1)." << std::endl;
    }
    //add on three
    std::cout << "reducing time\n12/36 reduces to " << object.reduce(12,36);
}

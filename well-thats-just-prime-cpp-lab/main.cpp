#include <iostream>

#include "src/prime.hpp"

int main() {
    Factorizer object;

    printFactors(object.primeFactors(getNumber()));
}

#include <string>
#include <vector>

class Factorizer {
public:
    std::vector<int> primeFactors(int number);
    bool isPrime(int number);
    bool isComposite(int number);
    std::string reduce(int numerator, int denominator);
};

int getNumber();
void printFactors(std::vector<int> factors);
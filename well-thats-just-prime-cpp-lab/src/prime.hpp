#include <string>
#include <vector>

class Factorizer {
public:
    std::vector<int> primeFactors(int number);
};

int getNumber();
void printFactors(std::vector<int> factors);
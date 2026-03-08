#include <iostream>

#include "src/complex.hpp"

int main() {
    ComplexNumber numberOne = ComplexNumber(5.0, 7.0);
    ComplexNumber numberTwo = ComplexNumber(2.5, 3.1);

    ComplexNumber numberThree = numberOne.addition(numberTwo);
    std::cout << numberThree.prettyPrint() << '\n'; // Returns 7.5 + 10.1i

    ComplexNumber numberFour = numberOne.subtraction(numberTwo);
    std::cout << numberFour.prettyPrint() << '\n'; // Returns 2.5 + 3.9i

    float magnitude = numberOne.magnitude();
    std::cout << magnitude << '\n'; // Returns 8.602325267
}

#include <iostream>

#include "src/complex.hpp"

int main() {
    ComplexNumber numberOne = ComplexNumber(5.0, 7.0);
    ComplexNumber numberTwo = ComplexNumber(2.0, 3.0);

    ComplexNumber numberThree = numberOne.addition(numberTwo);
    std::cout << numberThree.prettyPrint() << '\n'; // Returns 7.5 + 10.1i

    ComplexNumber numberFour = numberOne.subtraction(numberTwo);
    std::cout << numberFour.prettyPrint() << '\n'; // Returns 2.5 + 3.9i

    float magnitude = numberOne.magnitude();
    std::cout << magnitude << '\n'; // Returns 8.602325267

    float phase = numberOne.phase();
    std::cout << "phase: " << phase << '\n';

    ComplexNumber product = numberOne.multiplication(numberTwo);
    std::cout << "multiplication: " << product.prettyPrint() << '\n';
    ComplexNumber quotient = numberOne.division(numberTwo);
    std::cout << "division:       " << quotient.prettyPrint() << '\n';
}

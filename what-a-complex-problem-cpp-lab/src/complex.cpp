#include "complex.hpp"
#include <cmath>
#include <sstream>
#include <iostream>

#include <string>

ComplexNumber::ComplexNumber(float realInput, float imaginaryInput) {
    realNumber = realInput;
    imaginaryNumber = imaginaryInput;
}

ComplexNumber ComplexNumber::addition(ComplexNumber other) const {
    return ComplexNumber(realNumber + other.realNumber, imaginaryNumber + other.imaginaryNumber);
}
ComplexNumber ComplexNumber::subtraction(ComplexNumber other) const {
    return ComplexNumber(realNumber - other.realNumber, imaginaryNumber - other.imaginaryNumber);
}
ComplexNumber ComplexNumber::negate() const {
    return ComplexNumber(-realNumber, -imaginaryNumber);
}
float ComplexNumber::magnitude() const {
    return std::sqrt(realNumber * realNumber + imaginaryNumber * imaginaryNumber);
}
ComplexNumber ComplexNumber::conjugate() const {
    return ComplexNumber(realNumber, -imaginaryNumber);
}

std::string ComplexNumber::prettyPrint() const {
    std::ostringstream soonOutput;
    soonOutput << realNumber << " + " << imaginaryNumber << "i";
    return soonOutput.str();
}

float ComplexNumber::real() const {
    return realNumber;
}
float ComplexNumber::imaginary() const {
    return imaginaryNumber;
}
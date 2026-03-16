#include <string>

class ComplexNumber {
private:
    float realNumber;
    float imaginaryNumber;
public:
    ComplexNumber(float realInput = 0.0, float imaginaryInput = 0.0);

    ComplexNumber addition(ComplexNumber other) const;
    ComplexNumber subtraction(ComplexNumber other) const;
    ComplexNumber negate() const;
    float magnitude() const;
    ComplexNumber conjugate() const;

    float phase() const;
    ComplexNumber multiplication(ComplexNumber other) const;
    ComplexNumber division(ComplexNumber other) const;

    std::string prettyPrint() const;

    float real() const;
    float imaginary() const;




};

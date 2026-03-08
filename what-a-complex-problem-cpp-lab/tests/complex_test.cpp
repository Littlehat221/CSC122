#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/complex.hpp"

TEST_CASE("Addition test") {
    ComplexNumber a(5.0, 7.0);
    ComplexNumber b(2.5, 3.1);

    ComplexNumber result = a.addition(b);
    
    REQUIRE(std::abs(result.real() - 7.5) < 0.0001);
    REQUIRE(std::abs(result.imaginary() - 10.1) < 0.0001);
}

TEST_CASE("Subtraction test") {
    ComplexNumber a(5.0, 7.0);
    ComplexNumber b(2.5, 3.1);

    ComplexNumber result = a.subtraction(b);
    
    REQUIRE(std::abs(result.real() - 2.5) < 0.0001);
    REQUIRE(std::abs(result.imaginary() - 3.9) < 0.0001);
}

TEST_CASE("Negation test") {
    ComplexNumber a(5.0, -7.0);

    ComplexNumber result = a.negate();

    REQUIRE(result.real() == -5.0);
    REQUIRE(result.imaginary() == 7.0);
}

TEST_CASE("Magnitude test") {
    ComplexNumber a(5.0, 7.0);

    float mag = a.magnitude();
    
    REQUIRE(std::abs(mag - 8.602325267) < 0.0001);
}

TEST_CASE("Conjugation test") {
    ComplexNumber a(5.0, 7.0);

    ComplexNumber result = a.conjugate();

    REQUIRE(result.real() == 5.0);
    REQUIRE(result.imaginary() == -7.0);
}

TEST_CASE("prettyPrint test") {
    ComplexNumber a(5.0, 7.0);

    REQUIRE(a.prettyPrint() == "5 + 7i");
}
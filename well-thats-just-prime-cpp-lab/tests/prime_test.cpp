#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include <vector>
#include "../src/prime.hpp"

TEST_CASE("numbers <= 1 return empty vector")
{
    Factorizer thingy;

    REQUIRE(thingy.primeFactors(0).empty());
    REQUIRE(thingy.primeFactors(1).empty());
    REQUIRE(thingy.primeFactors(-5).empty());
}

TEST_CASE("prime numbers return themselves?")
{
    Factorizer thingy;

    REQUIRE(thingy.primeFactors(2) == std::vector<int>{2});

    REQUIRE(thingy.primeFactors(593) == std::vector<int>{593});
}

TEST_CASE("composite numbers factor?")
{
    Factorizer thingy;

    REQUIRE(thingy.primeFactors(9) == std::vector<int>{3,3});

    REQUIRE(thingy.primeFactors(10) ==std::vector<int>{2,5});
}

TEST_CASE("many prime factors?")
{
    Factorizer thingy;

    REQUIRE(thingy.primeFactors(24) == std::vector<int>{2,2,2,3});

    REQUIRE(thingy.primeFactors(1000) == std::vector<int>{2,2,2,5,5,5});
}
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

TEST_CASE( "Check for -1 / second string character mismatch greater" ) {
    REQUIRE( strcmp_case_insensitive("String one","string two") == -1 );
}
TEST_CASE( "Check for 0 / same string" ) {
    REQUIRE( strcmp_case_insensitive("String one","string one") == 0 );
}
TEST_CASE( "Check for +1 / first string character mismatch greater" ) {
    REQUIRE( strcmp_case_insensitive("String two","string one") == 1 );
}

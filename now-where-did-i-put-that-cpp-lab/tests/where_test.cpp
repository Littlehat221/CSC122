#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/where.hpp"

TEST_CASE("Example output 1: returns 2 for char") {
    REQUIRE(find("The quick brown fox", 'e') == 2);
}
TEST_CASE("Example output 2: returns 2 for string") {
    REQUIRE(find("The quick brown fox", "e") == 2);
}
TEST_CASE("Example output 3: returns 3 for char") {
    REQUIRE(find("The quick brown fox", ' ') == 3);
}
TEST_CASE("Example output 4: returns 4 for string") {
    REQUIRE(find("The quick brown fox", "quick") == 4);
}
TEST_CASE("Example output 5: returns -1 for string") {
    REQUIRE(find("The quick brown fox", "quiet") == -1);
}


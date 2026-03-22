#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/point.hpp"

#include <cmath>

TEST_CASE("==") {
    Point p1(3.2, 9.8);
    Point p2(3.2, 9.8);
    Point p3(5.5, -1.2);

    REQUIRE(p1 == p2);
    REQUIRE_FALSE(p1 == p3);
}

TEST_CASE("!=") {
    Point p1(3.2, 9.8);
    Point p2(5.5, -1.2);

    REQUIRE(p1 != p2);
    REQUIRE_FALSE(p1 != Point(3.2, 9.8));
}

TEST_CASE("invalid  throws") {
    Point p(3.2, 9.8);

    REQUIRE_THROWS(p['z']);
}

TEST_CASE("<<"") {
    Point p(3.2, 9.8);

    std::ostringstream oss;
    oss << p;

    REQUIRE(oss.str() == "(3.2, 9.8)");
}
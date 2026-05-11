#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/link.hpp"

TEST_CASE("Link stores material") {
    Link gold("Gold");

    REQUIRE(gold.get_material() == "Gold");
}

TEST_CASE("Node stores link") {
    Link gold("Gold");
    Node node_one(&gold);

    REQUIRE(node_one.get_data()->get_material() == "Gold");
    REQUIRE(node_one.get_next() == nullptr);
}

TEST_CASE("Node attatched to another") {
    Link gold("Gold");
    Node node_one(&gold);

    Link silver("Silver");
    Node node_two(&silver, &node_one);

    REQUIRE(node_one.get_next() == &node_two);
    REQUIRE(node_one.get_next()->get_data()->get_material() == "Silver");
}
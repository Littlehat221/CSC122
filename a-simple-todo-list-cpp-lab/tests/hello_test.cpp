#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

TEST_CASE("Cannot add an empty task") {
    TodoList list;

    REQUIRE(list.add("") == false);
}
TEST_CASE("Cannot add duplicate incomplete task") {
    TodoList list;

    REQUIRE(list.add("Buy milk") == true);
    REQUIRE(list.add("Buy milk") == false);
}
TEST_CASE("Can add duplicate of completed task") {
    TodoList list;

    REQUIRE(list.add("Buy milk") == true);
    REQUIRE(list.complete("Buy milk") == true);
    REQUIRE(list.add("Buy milk") == true);
}
TEST_CASE("Cannot complete a task that does not exist") {
    TodoList list;

    REQUIRE(list.complete("Does not exist") == false);
}

TEST_CASE("Cannot complete an empty task name") {
    TodoList list;

    REQUIRE(list.complete("") == false);
}

TEST_CASE("Cannot complete an already completed task") {
    TodoList list;

    REQUIRE(list.add("Read chapter 3") == true);
    REQUIRE(list.complete("Read chapter 3") == true);
    REQUIRE(list.complete("Read chapter 3") == false);
}
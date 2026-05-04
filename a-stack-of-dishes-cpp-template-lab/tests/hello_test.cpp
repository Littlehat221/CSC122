#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/dish.hpp"

TEST_CASE("push does not add a Dish when the stack is full") {
    DishStack<Dish> stack;

    Dish dish1("Dish 1");
    Dish dish2("Dish 2");
    Dish dish3("Dish 3");
    Dish dish4("Dish 4");
    Dish dish5("Dish 5");
    Dish dish6("Dish 6");
    Dish dish7("Dish 7");
    Dish dish8("Dish 8");
    Dish dish9("Dish 9");
    Dish dish10("Dish 10");
    Dish extra_dish("Extra dish");

    stack.push(dish1);
    stack.push(dish2);
    stack.push(dish3);
    stack.push(dish4);
    stack.push(dish5);
    stack.push(dish6);
    stack.push(dish7);
    stack.push(dish8);
    stack.push(dish9);
    stack.push(dish10);

    REQUIRE(stack.size() == 10);
    REQUIRE(stack.isFullCheck() == true);

    stack.push(extra_dish);

    REQUIRE(stack.size() == 10);
    REQUIRE(stack.peek().get_description() == "Dish 10");
}
TEST_CASE("clear removes all elements from the stack") {
    DishStack<Dish> stack;
    Dish one_dish("A dish with one fish pattern on it");
    Dish two_dish("A dish with two fish patterns on it");
    Dish red_dish("A dish with a red fish pattern on it");

    stack.push(one_dish);
    stack.push(two_dish);
    stack.push(red_dish);

    REQUIRE(stack.size() == 3);

    stack.clear();

    REQUIRE(stack.size() == 0);
    REQUIRE(stack.isEmptyCheck() == true);
    REQUIRE(stack.isFullCheck() == false);
}
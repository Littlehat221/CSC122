#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/slide.hpp"

bool arraysEqual(int a[], int b[], int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

TEST_CASE("testing arrayshiftleft") {
    int arr[] = {1, 2, 3, 4, 5};

    int expected1[] = {2, 3, 4, 5, 1};
    arrayShiftLeft(arr, 5, 1);
    REQUIRE(arraysEqual(arr, expected1, 5));

    int expected2[] = {3, 4, 5, 1, 2};
    arrayShiftLeft(arr, 5, 1);
    REQUIRE(arraysEqual(arr, expected2, 5));

    int expected3[] = {4, 5, 1, 2, 3};
    arrayShiftLeft(arr, 5, 1);
    REQUIRE(arraysEqual(arr, expected3, 5));
}
TEST_CASE("testing arrayshiftright") {
    int arr[] = {1, 2, 3, 4, 5};

    int expected1[] = {5, 1, 2, 3, 4};
    arrayShiftRight(arr, 5, 1);
    REQUIRE(arraysEqual(arr, expected1, 5));

    int expected2[] = {4, 5, 1, 2, 3};
    arrayShiftRight(arr, 5, 1);
    REQUIRE(arraysEqual(arr, expected2, 5));

    int expected3[] = {3, 4, 5, 1, 2};
    arrayShiftRight(arr, 5, 1);
    REQUIRE(arraysEqual(arr, expected3, 5));
}
TEST_CASE("testing vectorshift") {
    std::vector<int> arr = {1, 2, 3, 4, 5};

    std::vector<int> expected = {2, 3, 4, 5, 1};
    vectorShift(arr, 1);
    REQUIRE(expected == arr);
}

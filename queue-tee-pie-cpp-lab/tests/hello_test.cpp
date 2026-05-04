#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>


#include "../src/cutie.hpp"

TEST_CASE("Cricle backing queue") {
    QueueTees<Cutie> queue;
    Puppy puppy1;
    Kitty kitty;
    PygmyMarmoset marmoset;
    Puppy puppy2;

    queue.enqueue(puppy1);
    queue.enqueue(kitty);
    queue.enqueue(marmoset);

    Cutie* first = queue.dequeue();

    REQUIRE(first->get_description() == "puppy");
    REQUIRE(queue.size() == 2);

    queue.enqueue(puppy2);

    REQUIRE(queue.size() == 3);
    REQUIRE(queue.isFullCheck() == true);

    Cutie* second = queue.dequeue();
    Cutie* third = queue.dequeue();
    Cutie* fourth = queue.dequeue();

    REQUIRE(second->get_description() == "kitty");
    REQUIRE(third->get_description() == "PygmyMarmoset");
    REQUIRE(fourth->get_description() == "puppy");
}

TEST_CASE("Does not add when full") {
    QueueTees<Cutie> queue;
    Puppy puppy;
    Kitty kitty;
    PygmyMarmoset marmoset;
    Puppy extra_puppy;

    queue.enqueue(puppy);
    queue.enqueue(kitty);
    queue.enqueue(marmoset);

    REQUIRE(queue.size() == 3);
    REQUIRE(queue.isFullCheck() == true);

    queue.enqueue(extra_puppy);

    REQUIRE(queue.size() == 3);
    REQUIRE(queue.isFullCheck() == true);
}
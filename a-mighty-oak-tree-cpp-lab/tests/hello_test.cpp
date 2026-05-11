#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"
TEST_CASE("Node stores Squirrel") {
    Squirrel cheeks("Cheeks");
    Node<Squirrel> node(&cheeks);

    REQUIRE(node.get_data()->get_name() == "Cheeks");
}

TEST_CASE("Left and right children can be assigned") {
    Squirrel root("Root");
    Squirrel left("Left");
    Squirrel right("Right");

    Node<Squirrel> root_node(&root);
    Node<Squirrel> left_node(&left);
    Node<Squirrel> right_node(&right);

    root_node.set_left(&left_node);
    root_node.set_right(&right_node);

    REQUIRE(root_node.left()->get_data()->get_name() == "Left");
    REQUIRE(root_node.right()->get_data()->get_name() == "Right");
}

TEST_CASE("Tree traversal via left/right pointers works") {
    Squirrel a("A");
    Squirrel b("B");
    Squirrel c("C");

    Node<Squirrel> node_a(&a);
    Node<Squirrel> node_b(&b);
    Node<Squirrel> node_c(&c);

    node_a.set_left(&node_b);
    node_a.set_right(&node_c);

    Node<Squirrel>* current = node_a.left();
    REQUIRE(current->get_data()->get_name() == "B");

    current = node_a.right();
    REQUIRE(current->get_data()->get_name() == "C");
}

TEST_CASE("Uninitialized children are nullptr") {
    Squirrel root("Root");
    Node<Squirrel> node(&root);

    REQUIRE(node.left() == nullptr);
    REQUIRE(node.right() == nullptr);
}
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

TEST_CASE("student breaking works?") {
    Student s("Bob Bobberson", "ABC123");

    REQUIRE(s.get_first_name() == "Bob");
    REQUIRE(s.get_last_name() == "Bobberson");
    REQUIRE(s.get_full_name() == "Bob Bobberson");
}

TEST_CASE("assignment store correctly?") {
    Assignment a("Quiz 1", 100);

    REQUIRE(a.get_assignment_name() == "Quiz 1");
    REQUIRE(a.get_total_points() == 100);
}

TEST_CASE("grade store correctly?") {
    Gradebook g;

    g.add_student("Bob Bobberson", "ABC123");
    g.add_assignment("Quiz 1", 100);

    g.enter_grade("Bob Bobberson", "Quiz 1", 85);

    std::string report = g.report();

    REQUIRE(report.find("85") != std::string::npos);
}

TEST_CASE("show none?") {
    Gradebook g;

    g.add_student("Bob Bobberson", "ABC123");
    g.add_assignment("Quiz 1", 100);

    std::string report = g.report();

    REQUIRE(report.find("none") != std::string::npos);
}

TEST_CASE("avg calc work?") {
    Gradebook g;

    g.add_student("Bob Bobberson", "ABC123");
    g.add_assignment("Quiz 1", 100);
    g.add_assignment("Lab 1", 50);

    g.enter_grade("Bob Bobberson", "Quiz 1", 100);
    g.enter_grade("Bob Bobberson", "Lab 1", 50);

    std::string report = g.report();

    REQUIRE(report.find("100.000") != std::string::npos);
}

TEST_CASE("assignment report calc avg?") {
    Gradebook g;

    g.add_student("A A", "1");
    g.add_student("B B", "2");

    g.add_assignment("Lab 1", 50);

    g.enter_grade("A A", "Lab 1", 50);
    g.enter_grade("B B", "Lab 1", 0);

    std::string report = g.assignment_report("Lab 1");

    REQUIRE(report.find("25") != std::string::npos); // avg = 25
}
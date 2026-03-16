#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/tictactoe.hpp"


TEST_CASE("Board initializes correctly")
{
    TicTacToe game;

    // After initialization, all positions should accept moves
    REQUIRE(game.makeMove(1) == true);
}

TEST_CASE("Valid move is accepted")
{
    TicTacToe game;

    bool result = game.makeMove(5);

    REQUIRE(result == true);
}

TEST_CASE("Invalid move outside range is rejected")
{
    TicTacToe game;

    REQUIRE(game.makeMove(0) == false);
    REQUIRE(game.makeMove(10) == false);
}

TEST_CASE("Cannot move in an occupied cell")
{
    TicTacToe game;

    REQUIRE(game.makeMove(3) == true);
    REQUIRE(game.makeMove(3) == false);
}

TEST_CASE("Player switching works")
{
    TicTacToe game;

    // first move should be X
    REQUIRE(game.makeMove(1) == true);

    game.switchPlayer();

    // second move should succeed for O
    REQUIRE(game.makeMove(2) == true);
}

TEST_CASE("Winning condition is detected")
{
    TicTacToe game;

    game.makeMove(1);
    game.makeMove(2);
    game.makeMove(3);

    REQUIRE(game.checkWin() == true);
}

TEST_CASE("Draw condition is detected")
{
    TicTacToe game;

    game.makeMove(1);
    game.makeMove(2);
    game.makeMove(3);
    game.makeMove(5);
    game.makeMove(4);
    game.makeMove(6);
    game.makeMove(8);
    game.makeMove(7);
    game.makeMove(9);

    REQUIRE(game.checkDraw() == true);
}
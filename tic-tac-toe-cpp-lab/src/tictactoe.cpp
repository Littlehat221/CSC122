#include "tictactoe.hpp"
#include <iostream>
#include <string>
#include <cctype>

TicTacToe::TicTacToe()
{
    resetBoard();
}

void TicTacToe::resetBoard()
{
    for (int i = 0; i < 9; i++)
    {
        board[i] = '1' + i;
    }

    whoPlays = 'X';
}

void TicTacToe::printBoard() const
{
    std::cout << "\n";
    std::cout << "    " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
    std::cout << "  -----+-----+-----\n";
    std::cout << "    " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
    std::cout << "  -----+-----+-----\n";
    std::cout << "    " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n\n";
}

bool TicTacToe::makeMove(int position)
{
    if (position < 1 || position > 9)
    {
        return false;
    }

    int index = position - 1;

    if (board[index] == 'X' || board[index] == 'O')
    {
        return false;
    }

    board[index] = whoPlays;
    return true;
}

bool TicTacToe::checkWin() const
{
    int winPatterns[8][3] =
    {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };

    for (auto &pattern : winPatterns)
    {
        if (board[pattern[0]] == whoPlays && board[pattern[1]] == whoPlays && board[pattern[2]] == whoPlays)
        {
            return true;
        }
    }

    return false;
}

bool TicTacToe::checkDraw() const
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] != 'X' && board[i] != 'O')
        {
            return false;
        }
    }

    return true;
}

int TicTacToe::getMove()
{
    std::string input;

    while (true)
    {
        std::cout << "What is your move? ";
        std::getline(std::cin, input);

        if (input.empty())
        {
            std::cout << "\nThat is not a valid move! Try again.\n\n";
            continue;
        }

        for (char c : input)
        {
            if (!isdigit(c))
            {
                std::cout << "\nThat is not a valid move! Try again.\n\n";
                input = "";
                break;
            }
        }

        if (input.empty())
        {
            continue;
        }

        int move = std::stoi(input);

        if (!makeMove(move))
        {
            std::cout << "\nThat is not a valid move! Try again.\n\n";
            continue;
        }

        return move;
    }
}

void TicTacToe::switchPlayer()
{
    if (whoPlays == 'X')
        whoPlays = 'O';
    else
        whoPlays = 'X';
}

void TicTacToe::playGame()
{
    bool gameOver = false;

    while (!gameOver)
    {
        printBoard();

        getMove();

        if (checkWin())
        {
            printBoard();
            std::cout << "Player " << whoPlays << " wins!\n";
            gameOver = true;
        }
        else if (checkDraw())
        {
            printBoard();
            std::cout << "The game is a draw!\n";
            gameOver = true;
        }
        else
        {
            switchPlayer();
        }
    }
}
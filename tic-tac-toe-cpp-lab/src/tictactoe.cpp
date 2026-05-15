#include "tictactoe.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

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
    xIsComputer = false;
    oIsComputer = false;
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
    if (isTrap == true && position == trapCell) {
        std::cout << "\nOh no! " << whoPlays << " set off the trap! " << whoPlays << " loses their turn.\n";
        return true;
    }
    else {
        board[index] = whoPlays;
        return true;
    }
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
            if (isTrap == false || (isTrap == true && (board[i] - '0') != trapCell)) {
                return false;
            }
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

        bool allDigits = true;
        for (int i = 0; i < static_cast<int>(input.length()); i++)
        {
            if (!std::isdigit(static_cast<unsigned char>(input[i])))
            {
                allDigits = false;
                break;
            }
        }

        if (!allDigits)
        {
            std::cout << "\nThat is not a valid move! Try again.\n\n";
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
    changeGameMode();

    bool gameOver = false;

    while (!gameOver)
    {
        if (isComputerTurn() == false) {
            printBoard();
        }

        if (isComputerTurn())
        {
            getCompuerMove();
        }
        else
        {
            getMove();
        }

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
bool TicTacToe::isComputerTurn() {
    if (whoPlays == 'X')
    {
        return xIsComputer;
    }

    return oIsComputer;
}
bool TicTacToe::isOpenSpot(int position) {
    if (position < 1 || position > 9)
    {
        return false;
    }

    int index = position - 1;
    return board[index] != 'X' && board[index] != 'O';
}
void TicTacToe::changeGameMode() {
    {
        std::string input;

        while (true)
        {
            std::cout << "\nWhat kind of game would you like to play?\n\n";
            std::cout << "1. Human vs. Human\n";
            std::cout << "2. Human vs. Computer\n";
            std::cout << "3. Computer vs. Human\n\n";
            std::cout << "What is your selection? ";
            std::getline(std::cin, input);

            if (input == "1")
            {
                xIsComputer = false;
                oIsComputer = false;
                std::cout << "\nGreat! Player X will go first.\n";
            }
            else if (input == "2")
            {
                xIsComputer = false;
                oIsComputer = true;
                std::cout << "\nGreat! The computer will go second.\n";
            }
            else if (input == "3")
            {
                xIsComputer = true;
                oIsComputer = false;
                std::cout << "\nGreat! The computer will go first.\n";
            }
            else
            {
                std::cout << "\nPlease choose 1 2 or 3.\n";
            }
            while (true) {
                std::cout << "\nWould you like to include a trap cell in your game?\n\n";
                std::cout << "1. Yes\n";
                std::cout << "2. No\n\n";
                std::cout << "What is your selection? ";
                std::getline(std::cin, input);
                if (input == "1") {
                    std::cout << "\nGreat! A trap has been hidden on the board.\n\n";
                    isTrap = true;
                    trapCell = std::rand() % 10;
                    return;
                }
                else if (input == "2") {
                    std::cout << "\nThis game does not have a trap hidden on the board.\n\n";
                    isTrap = false;
                    return;
                }
                else {
                    std::cout << "\nPlease choose 1 2 or 3.\n";
                }
            }

        }
    }
}
int TicTacToe::getCompuerMove() {
        int openSpots[9];
        int openCount = 0;

        for (int position = 1; position <= 9; position++)
        {
            if (isOpenSpot(position))
            {
                openSpots[openCount] = position;
                openCount++;
            }
        }

        int randomIndex = std::rand() % openCount;
        int move = openSpots[randomIndex];
        makeMove(move);
        return move;
}
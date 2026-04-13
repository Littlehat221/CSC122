#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

#include "src/tictactoe.hpp"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::cout << "Welcome to Tic-Tac-Toe!\n";

    bool playAgain = true;

    while (playAgain)
    {
        TicTacToe game;
        game.playGame();

        std::string response;

        while (true)
        {
            std::cout << "\nWould you like to play again (yes/no)? ";
            std::getline(std::cin, response);

            if (response == "yes")
            {
                playAgain = true;
                break;
            }
            else if (response == "no")
            {
                playAgain = false;
                break;
            }
            else
            {
                std::cout << "\nThat is not a valid entry!\n";
            }
        }
    }

    std::cout << "\nGoodbye!";
}
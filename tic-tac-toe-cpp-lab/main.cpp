#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "src/tictactoe.hpp"

int main(void)
{
    std::cout<< "Welcome to Tic-Tac_Toe!\n";
    //draws example board
    draw(10,'e');
    while (1)
    {
        X = 0;
        O = 0;
        //gets first guy

        X = oops(1,9,"X's move: ", "That is not a valid move! Try again.");

        draw(X, 'X');
        tiecheck();
        check('X');

        //gets second guy

        O = oops(1,9,"O's move: ", "That is not a valid move! Try again.");

        draw(O, 'O');
        tiecheck();
        check('O');
    }
}
#include <string>

class TicTacToe
{
private:
    char board[9];
    char whoPlays;
    bool xIsComputer;
    bool oIsComputer;
    bool isTrap;
    int trapCell;

public:
    TicTacToe();

    void resetBoard();
    void printBoard() const;
    bool makeMove(int position);
    bool checkWin() const;
    bool checkDraw() const;
    int getMove();
    void switchPlayer();
    void playGame();
    bool isComputerTurn();
    bool isOpenSpot(int position);
    void changeGameMode();
    int getCompuerMove();

};

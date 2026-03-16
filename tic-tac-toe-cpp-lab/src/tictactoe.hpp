#include <string>

class TicTacToe
{
private:
    char board[9];
    char whoPlays;

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
};

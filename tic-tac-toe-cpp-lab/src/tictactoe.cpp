#include <string>
#include <cstdlib>
#include <iostream>
#include <limits>

// Your code goes here
extern int taken[9] = {0,0,0,0,0,0,0,0,0};
extern int X = 0;
extern int O = 0;
extern int grid[3][3] =
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void draw(int input, char who)
{
    //works at and not at start
    if (input == 10) {
        for (int num = 1; num < 9; num+=3)
        {
            std::cout<< num << ' ' << num+1 << ' ' << num+2 << '\n';
        }
        return;
    }
    //determing where
    switch (input)
    {
        case 1:
            grid[0][0] = who;
            taken[0] = 1;
            break;
        case 2:
            grid[0][1] = who;
            taken[1] = 2;
            break;
        case 3:
            grid[0][2] = who;
            taken[2] = 3;
            break;
        case 4:
            grid[1][0] = who;
            taken[3] = 4;
            break;
        case 5:
            grid[1][1] = who;
            taken[4] = 5;
            break;
        case 6:
            grid[1][2] = who;
            taken[5] = 6;
            break;
        case 7:
            grid[2][0] = who;
            taken[6] = 7;
            break;
        case 8:
            grid[2][1] = who;
            taken[7] = 8;
            break;
        case 9:
            grid[2][2] = who;
            taken[8] = 9;
            break;
        default:
            std::cout << "AN EXCEPTION OCCURED AT MEMORY ADDRESS" << &input << "TERMINATE TERMINAL NOW.\n";
            exit(0);;
    }
    //actually drawing now
    std::cout << "\n";
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            std::cout << (char)grid[y][x] << ' ';
        }
        std::cout << "\n";
    }
}

void check(char who)
{
    //there are 8 ways to win, so this covers all of that
    //i'm forced to do if/else ladder to compute looks pretty bad.
    if (grid[0][0] == who && grid[0][1] == who && grid[0][2] == who)
    {
        std::cout << who << " wins!\n";
        exit(0);
    }
    else if (grid[1][0] == who && grid[1][1] == who && grid[1][2] == who)
    {
        std::cout << who << " wins!\n";
        exit(0);
    }
    else if (grid[2][0] == who && grid[2][1] == who && grid[2][2] == who)
    {
        std::cout << who << " wins!\n";
        exit(0);
    }
    else if (grid[0][0] == who && grid[1][0] == who && grid[2][0] == who)
    {
        std::cout << who << " wins!\n";
        exit(0);
    }
    else if (grid[0][1] == who && grid[1][1] == who && grid[2][1] == who)
    {
        std::cout << who << " wins!\n";
        exit(0);
    }
    else if (grid[0][2] == who && grid[1][2] == who && grid[2][2] == who)
    {
        std::cout << who << " wins!\n";
        exit(0);
    }
    else if (grid[0][0] == who && grid[1][1] == who && grid[2][2] == who)
    {
        std::cout << who << " wins!\n";
        exit(0);
    }
    else if (grid[2][0] == who && grid[1][1] == who && grid[0][2] == who)
    {
        std::cout << who << " wins!\n";
        exit(0);
    }
}

void tiecheck(void)
{
    int check = 0;
    for (int x = 0; x < 8; x++)
    {
        if (taken[x] == 0)
        {
            check++;
        }
    }
    if (check == 0)
    {
        std::cout << "Tie, as always.\n";
        exit(0);
    }
}
int oops(int lower, int upper, std::string prompt, std::string error) {
    int number;

    std::cout << prompt << std::endl;

    while (!(std::cin >> number) || number < lower || number > upper || number == taken[0] || number == taken[1] || number == taken[2] || number == taken[3] || number == taken[4] || number == taken[5] || number == taken[6] || number == taken[7] || number == taken[8]) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << error << std::endl;
        std::cout << prompt << std::endl;
    }

    return number;
}

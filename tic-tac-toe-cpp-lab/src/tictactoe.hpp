extern int taken[9];
extern int X;
extern int O;
extern int grid[3][3];

void draw(int input, char who);
void check(char who);
void tiecheck(void);
int oops(int lower, int upper, std::string prompt, std::string error);
#include "Board.hh"
#include <cmath>
int between(int a, int b, int c)
{
    return ((a < b) && (b < c));
}
Board::Board()
{
    board = new char *[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        board[i] = new char[SIZE];
        for (int j = 0; j < SIZE; j++)
            board[i][j] = S;
    }
}
void Board::set(int y, int x, char c)
{
    if (get(y, x) == S)
        board[y][x] = c;
}
char Board::get(int y, int x)
{
    return board[y][x];
}
void Board::print()
{
    std::cout << "  ";
    for (int i = 0; i < SIZE; i++)
        std::cout << (char)(i + '0');
    std::cout << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (!j)
                std::cout << (char)(i + '0') << ' ';
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}
int Bishop::attack(int _y, int _x)
{
    return (abs(x - _x) == abs(y - _y));
}

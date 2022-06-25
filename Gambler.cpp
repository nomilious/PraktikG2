#include "Gambler.hh"

void Gambler::win()
{
    std::cout << name << " won!";
}
int Man::move(int y, int x)
{
    if (std::cin.bad() || bad_move(y, x) || board->get(y, x) != S)
    {
        std::cout << "ERROR!";
        exit(0);
    }
    board->set(y, x, P_1);
    std::cout << name << " move: " << y << "," << x << std::endl;
    bishops[2 * (pieces++)] = Bishop(y, x);
    return 0;
}
int Gambler::can_continue()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (!bad_move(i, j) && board->get(i, j) == S)
            {
                return 1;
            }
    return 0;
}
int Pc::move(int y, int x)
{
    x = SIZE - 1 - x;
    if (bad_move(y, x) || board->get(y, x) != S)
        return 1;

    board->set(y, x, P_2);
    std::cout << name << " move: " << y << "," << x << std::endl;
    bishops[(++pieces)++] = Bishop(y, x);
    return 0;
}
int Pc::bad_move(int y, int x)
{
    for (int k = 0, i = 0; i < pieces; k += 2, i++)
        if (bishops[k].attack(y, x))
            return 1;
    return 0;
}
int Man::bad_move(int y, int x)
{ // no enemy
    for (int k = 1; k < pieces * 2; k += 2)
        if (bishops[k].attack(y, x))
            return 1;
    return 0;
}

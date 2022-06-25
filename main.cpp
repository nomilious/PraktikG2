#include "Board.hh"
#include "Gambler.hh"
#include <ctime>
#include <iostream>
#include <vector>
int main()
{
    Board *b = new Board();
    Bishop *bishops = new Bishop[64];
    Gambler *player[] = {new Man(b, (char *)"player", bishops), new Pc(b, (char *)"pc", bishops)};
    int i = 0;
    char s[2];
    srand(time(NULL));
    do
    {
        if (!player[i % 2]->can_continue())
        {
            player[(i - 1) % 2]->win();
            return 0;
        }
        if (i % 2 == 0)
        { // if user moves
            std::cout << "\n\n";
            b->print();
            std::cin >> s[0] >> s[1];
            std::cout << '\n';
        }
    } while (!player[i++ % 2]->move(s[0] - '0', s[1] - '0'));
    player[i % 2]->win();
    return 0;
}

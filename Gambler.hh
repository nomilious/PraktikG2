#pragma once
#include "Board.hh"

class Gambler
{
protected:
    char *name;
    int pieces;
    Board *board;
    Bishop *bishops;

public:
    Gambler(Board *b, char *s, Bishop *bish) : board(b), name(s), bishops(bish){};
    Gambler(){};
    int can_continue();
    int getpieces() { return pieces; }
    void win();
    virtual int bad_move(int, int) = 0;
    virtual int move(int, int) = 0;
};
class Man : public Gambler
{
public:
    Man(Board *b, char *s, Bishop *bish) : Gambler(b, s, bish) {}
    virtual int move(int, int);
    virtual int bad_move(int, int);
};
class Pc : public Gambler
{
public:
    Pc(Board *b, char *s, Bishop *bish) : Gambler(b, s, bish) {}
    virtual int move(int, int);
    virtual int bad_move(int, int);
};

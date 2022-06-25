#pragma once
#include <iostream>
#define SIZE 8
#define S '#'
#define P_1 'F'
#define P_2 'f'

class Board
{
    char **board;

public:
    Board();
    void set(int, int, char);
    char get(int, int);
    void print();
};
class Bishop
{
    int y, x;

public:
    Bishop(int y, int x) : y(y), x(x){};
    Bishop(){};
    int attack(int, int);
};

#pragma once
#include <curses.h>
#include "Drawable.hpp"
#include <queue>

enum Direction {
    up,
    down,
    left,
    right
};

class SnakePiece : public Drawable
{
public:
    SnakePiece()
    {
        this->x = this->y = 0;
        this->icon = '#'

    }

    SnakePiece(int y, int x)
    {
        this->x = x;
        this->y = y;
        this->icon = '#';
    }
};

class Snake
{
    std::queue<SnakePiece> prev_pieces;
    Direction cur_direction;
public:
    Snake();

    void addPiece(SnakePiece piece);

    void removePiece();

    SnakePiece tail();

    SnakePiece head();

    Direction getDirection();

    void setDirection(Direction d);

    SnakePiece nextHead();
};
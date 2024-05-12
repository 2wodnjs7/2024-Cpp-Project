#include <iostream>
#include "snake.hpp"

using namespace std;

queue<SnakePiece> prev_pieces;
Direction cur_direction;

Snake::Snake()
{
    cur_direction = down;
}
void Snake::addPiece(SnakePiece piece)
{
    prev_pieces.push(piece);
}

void Snake::removePiece()
{
    prev_pieces.pop();  
}

SnakePiece tail()
{
    return prev_pieces.back();
}

SnakePiece head()
{
    return prev_pieces.front();
}

Direction getDirection()
{
    return cur_direction;
}

void setDirection(Direction d)
{
    cur_direction = d;
}

SnakePiece nextHead()
{
    int row = head().getY();
    int col = head().getX();

    switch (cur_direction)
    {
    case down:
        row++;
        break;
    case up:
        row--;
        break;
    case left:
        col++;
        break;
    case right:
        col--;
        break;
    }

    return SnakePiece(row, col);
}
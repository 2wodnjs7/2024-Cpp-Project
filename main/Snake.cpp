#include <iostream>
#include "Snake.hpp"

using namespace std;

Snake::Snake(Map *map) : thisMap(map)
{
    direction = _down;
}

void Snake::addPiece(Point piece)
{
    snakeQueue.push(piece);
}

void Snake::removePiece()
{
    snakeQueue.pop();
}

Point Snake::tail()
{
    return snakeQueue.front();
}

Point Snake::head()
{
    return snakeQueue.back();
}

Direction Snake::getDirection()
{
    return direction;
}

bool Snake::setDirection(Direction d)
{
    if ((this->direction + d) % 2 != 0)
        direction = d;
    else if (this->direction != d)
        return true;
    return false;
}

Point Snake::nextHead()
{  
    int row = head().getY();
    int col = head().getX();
    
    switch (direction)
    {
    case Direction::_up:
        row--;
        break;
    case Direction::_right:
        col++;
        break;
    case Direction::_down:
        row++;
        break;
    case Direction::_left:
        col--;
        break;
    }
    return Point(row, col);
}

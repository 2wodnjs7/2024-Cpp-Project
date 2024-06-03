#include "Point.hpp"

Point::Point(int y, int x): x(x), y(y)
{

}

Point Point::nextPoint(Direction direction)
{
    int row = this->getY();
    int col = this->getX();

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

Direction returnDirection(const int a)
{
    if (a == 0)
        return _up;
    else if (a == 1)
        return _right;
    else if (a == 2)
        return _down;
    return _left;
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

bool Point::operator==(const Point& nPoint)
{
    return (this->getX() == nPoint.getX()) && (this->getY() == nPoint.getY());
}
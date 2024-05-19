#include "Point.hpp"

Point::Point(int y, int x): x(x), y(y)
{

}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}
#ifndef __POINT__
#define __POINT__

enum Direction {
    _up = 0,
    _right = 1,
    _down = 2,
    _left = 3
};

Direction returnDirection(const int);

class Point{
public:
    Point(int y = 0, int x = 0);
    Point nextPoint(Direction direction);
    int getX() const;
    int getY() const;
    bool operator==(const Point& nPoint);
protected:
    int x, y;
};

#endif
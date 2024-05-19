#ifndef __POINT__
#define __POINT__

class Point{
public:
    Point(int y = 0, int x = 0);
    int getX() const;
    int getY() const;
protected:
    int x, y;
};

#endif
#ifndef __ITEM__
#define __ITEM__

#include <curses.h>
#include <cstdlib>
#include <random>
#include "Map.hpp"

const int ITEM_TIME = 10;

class Item {
public:
    Item(Map* map);
    Point& getPoint();
    bool makeItem(int& countSpace, const char ch);
    void setItem(const int item, Point& point, int& countSpace, const char ch);
    void deleteItem();
    void resetItem(int& countSpace, const char ch);
private:
    int resetTime = 1;
    int item = 0;
    Point point;
    Map* thisMap;
};

#endif


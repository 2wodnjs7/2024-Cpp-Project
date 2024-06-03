#ifndef __Items__
#define __Items__

#include <curses.h>
#include <cstdlib>
#include <random>
#include "Map.hpp"

using namespace std;

class Items{
public:
    Items(Map* map);
    int getCountSpace();
protected:
    Map* thisMap;
};

#endif
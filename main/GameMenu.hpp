#ifndef __GAMEMENU__
#define __GAMEMENU__

#include <curses.h>

using namespace std;

class GameMenu
{
public:
    GameMenu();
private:
    WINDOW* menu;
};

#endif
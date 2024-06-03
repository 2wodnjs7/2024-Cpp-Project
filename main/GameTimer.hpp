#ifndef __GAMETIMER__
#define __GAMETIMER__

#include "Window.hpp"

using namespace std;

class GameTimer : public Window
{
public:
    GameTimer(int height, int width, int y, int x);
    void initPrint();
    void printBoard();
    void upGameTime();
private:
    int gameTime;
};

#endif
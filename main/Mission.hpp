#ifndef __MISSION__
#define __MISSION__

#include "Window.hpp"

using namespace std;

class Mission : public Window
{
public:
    Mission(int height, int width, int y, int x);
    void update(int goal, int plus, int minus, int gate);
    void achieve();
    void printBoard();
private:
    int missionGoal = 0;
    int missionGrowth = 0;
    int missionPoison = 0;
    int missionGate = 0;
};

#endif
#ifndef __MISSION__
#define __MISSION__

#include "Window.hpp"

using namespace std;

class Mission : public Window
{
public:
    Mission(int height, int width, int y, int x);
    void init();
    void checkLength(const int maxLength);
    void checkGrowth(const int growthItems);
    void checkPoison(const int poisonItems);
    void checkUsedGates(const int usedGates);
    bool checkMission();
    void printBoard();
private:
    int missionLength = 10;
    int missionGrowth = 3;
    int missionPoison = 3;
    int missionGate = 1;
    bool boolLength = false;
    bool boolGrowth = false;
    bool boolPoison = false;
    bool boolGate = false;
};

#endif
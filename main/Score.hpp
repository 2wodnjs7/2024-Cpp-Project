#ifndef __SCORE__
#define __SCORE__

#include "Window.hpp"

using namespace std;

class Score : public Window
{
public:
    Score(int height, int width, int y, int x);
    int getMaxLength();
    int getGrowthItems();
    int getPoisonItems();
    int getUsedGates();
    void init();
    void updateLength(const char ch);
    void updateMaxLen(const int maxLen);
    void updateGrowth();
    void updatePoison();
    void updateUseGate();
    void printBoard();
private:
    int currentLength = 3;
    int maxLength = 3;
    int growthItems = 0;
    int poisonItems = 0;
    int usedGates = 0;
};

#endif
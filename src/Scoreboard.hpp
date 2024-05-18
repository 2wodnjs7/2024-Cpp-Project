#pragma once
#include <curses.h>
#include <fstream>
#include "Window.hpp"

using namespace std;

#define MAP_SIZE 23

class Score : public Window
{
    int currentLength = 0;
    int maxLength = 0;
    int growthItems = 0;
    int poisonItems = 0;
    int useGate = 0;

public:
    Score(int height, int width, int y, int x);

    void update(int length, int maxLen, int growth, int poison, int gates);
    void printBoard();
};

class Mission : public Window
{
    int missionGoal = 0;
    int missionGrowth = 0;
    int missionPoison = 0;
    int missionGate = 0;

public:
    Mission(int height, int width, int y, int x);

    void update(int goal, int plus, int minus, int gate);
    void achieve();
    void printBoard();
};
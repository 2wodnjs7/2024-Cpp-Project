#include "Mission.hpp"

Mission::Mission(int height, int width, int y, int x) {
    win = subwin(stdscr, height, width, y, x);
    init();
}

void Mission::init()
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i == 0 || i == 10 || j == 0 || j == 8)
                this->addCh(j, i * 2, '#');
        }
    }
    printBoard();
}

void Mission::checkLength(const int maxLength)
{
    if (maxLength == missionLength)
    {
        boolLength = true;
        mvwprintw(win, 3, 13, "v");
        wrefresh(win);
    }
}

void Mission::checkGrowth(const int growthItems)
{
    if (growthItems == missionGrowth)
    {
        boolGrowth = true;
        mvwprintw(win, 4, 13, "v");
        wrefresh(win);
    }
}

void Mission::checkPoison(const int poisonItems)
{
    if (poisonItems == missionPoison)
    {
        boolPoison = true;
        mvwprintw(win, 5, 13, "v");
        wrefresh(win);
    }
}

void Mission::checkUsedGates(const int usedGates)
{
    if (usedGates == missionGate)
    {
        boolGate = true;
        mvwprintw(win, 6, 13, "v");
        wrefresh(win);
    }
}

bool Mission::checkMission()
{
    if (boolLength && boolGrowth && boolPoison && boolGate)
        return true;
    else
        return false;
}

void Mission::printBoard() 
{
    mvwprintw(win, 2, 3, "Mission");
    mvwprintw(win, 3, 3, "B: (%d)  ( )", missionLength);
    mvwprintw(win, 4, 3, "+: (%d)   ( )", missionGrowth);
    mvwprintw(win, 5, 3, "-: (%d)   ( )", missionPoison);
    mvwprintw(win, 6, 3, "G: (%d)   ( )", missionGate);
    wrefresh(win);
}
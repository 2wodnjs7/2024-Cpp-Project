#include "Score.hpp"

Score::Score(int height, int width, int y, int x) {
    win = subwin(stdscr, height, width, y, x);
    init();
}

void Score::init()
{
    currentLength = 3;
    maxLength = 3;
    growthItems = 0;
    poisonItems = 0;
    usedGates = 0;
    printBoard();
}

void Score::updateLength(const char ch)
{
    if (ch == '+')
        updateGrowth();
    else if (ch == '-')
        updatePoison();
    updateMaxLen(currentLength);
    printBoard();
}

void Score::updateMaxLen(const int maxLen)
{
    if(maxLength < maxLen)
        maxLength = maxLen;
    printBoard();
}

void Score::updateGrowth()
{
    currentLength++;
    growthItems++;
    printBoard();
}

void Score::updatePoison()
{
    currentLength--;
    poisonItems++;
    printBoard();
}

void Score::updateUseGate()
{
    usedGates++;
    printBoard();
}



void Score::printBoard() {
    mvwprintw(win, 0, 0, "Score Board");
    mvwprintw(win, 1, 0, "Length: %d", currentLength);
    mvwprintw(win, 2, 0, "Max Length: %d", maxLength);
    mvwprintw(win, 3, 0, "Growth Items: %d", growthItems);
    mvwprintw(win, 4, 0, "Poison Items: %d", poisonItems);
    mvwprintw(win, 5, 0, "Used Gates: %d", usedGates);
    wrefresh(win);
}
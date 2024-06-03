#include "Score.hpp"

Score::Score(int height, int width, int y, int x){
    win = subwin(stdscr, height, width, y, x);
    init();
}

int Score::getMaxLength()
{
    return maxLength;
}

int Score::getGrowthItems()
{
    return growthItems;
}

int Score::getPoisonItems()
{
    return poisonItems;
}

int Score::getUsedGates()
{
    return usedGates;
}

void Score::init()
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
    
    mvwprintw(win, 2, 3, "Score Board");
    mvwprintw(win, 3, 3, "B: (%d) / (%d)", currentLength, maxLength);
    mvwprintw(win, 4, 3, "+: (%d)", growthItems);
    mvwprintw(win, 5, 3, "-: (%d)", poisonItems);
    mvwprintw(win, 6, 3, "G: (%d)", usedGates);
    wrefresh(win);
}
#include "GameTimer.hpp"

GameTimer::GameTimer(int height, int width, int y, int x) {
    win = subwin(stdscr, height, width, y, x);
    gameTime = 0;
    initPrint();
}

void GameTimer::initPrint()
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0 || i == 10 || j == 0 || j == 4)
                this->addCh(j, i * 2, '#');
        }
    }
    printBoard();
}

void GameTimer::printBoard()
{
    mvwprintw(win, 2, 2, " GameTime : %d", gameTime);
    wrefresh(win);
}

void GameTimer::upGameTime()
{
    gameTime++;
    printBoard();
}
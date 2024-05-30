#include <iostream>
#include <curses.h>
#include "GameProcess.hpp"

const int mapRows = MAP_SIZE;
const int mapCols = MAP_SIZE * 2;

int main(int argc, char** argv)
{
    initscr();
    start_color();
	
    GameProcess gameProcess(mapRows, mapCols);
    gameProcess.init();

    while (!gameProcess.isOver())
    {   
        gameProcess.inputGame();
        gameProcess.updateGame();
        gameProcess.reDraw();         // 다시 출력
        gameProcess.setTick(1000);    // 1초 지연시간
    }

    getch();
    endwin();

    return 0;
}
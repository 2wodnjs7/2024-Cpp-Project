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

    while (!gameProcess.isOver())
    {   
        gameProcess.reDraw();       // 다시 출력
        gameProcess.tick(1);        // 1초 지연시간
        gameProcess.deleteGate();   // 게이트 삭제
        gameProcess.makeGate();     // 게이트 생성
    }

    getch();
    endwin();

    return 0;
}
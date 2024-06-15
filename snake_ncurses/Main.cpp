#include <iostream>
#include <curses.h>
#include "GameProcess.hpp"

const int mapRows = MAP_SIZE;
const int mapCols = MAP_SIZE * 2;

int main(int argc, char** argv)
{
    initscr();
    start_color();
    setlocale(LC_ALL, "");
    
    GameProcess gameProcess(mapRows, mapCols);

    while (!gameProcess.isOver())
    {   
        gameProcess.inputGame();                // 사용자 키보드 입력
        gameProcess.updateGame();               // 
        if (gameProcess.isOver())               // GameOver시 다시 출력할 필요 없이 게임 종료     
            break;
        gameProcess.reDraw();                   // 다시 출력
        gameProcess.setTick(1000);              // 1초 지연시간
    }

    getch();
    endwin();

    return 0;
}
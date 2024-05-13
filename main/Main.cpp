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
        gameProcess.reDraw();       // �ٽ� ���
        gameProcess.tick(1);        // 1�� �����ð�
        gameProcess.deleteGate();   // ����Ʈ ����
        gameProcess.makeGate();     // ����Ʈ ����
    }

    getch();
    endwin();

    return 0;
}
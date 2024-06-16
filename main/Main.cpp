#include <iostream>
#include <curses.h>
#include "GameProcess.hpp"

const int mapRows = MAP_SIZE;
const int mapCols = MAP_SIZE * 2;

int main(int argc, char **argv)
{
    initscr();
    start_color();
    setlocale(LC_ALL, "");

    GameProcess gameProcess(mapRows, mapCols);

    while (!gameProcess.isOver())
    {
        gameProcess.inputGame();  // ����� Ű���� �Է�
        gameProcess.updateGame(); //
        if (gameProcess.isOver()) // GameOver�� �ٽ� ����� �ʿ� ���� ���� ����
            break;
        gameProcess.reDraw();     // �ٽ� ���
        gameProcess.setTick(200); // 1�� �����ð�
    }

    getch();
    endwin();

    return 0;
}
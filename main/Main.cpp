#pragma once
#include <iostream>
#include <curses.h>
#include "Map.hpp"

const int mapRows = MAP_SIZE;
const int mapCols = MAP_SIZE * 2;

int main(int argc, char** argv)
{
    initscr();
    start_color();
	 
    Map map(mapRows, mapCols);

    getch();
    endwin();

    return 0;
}
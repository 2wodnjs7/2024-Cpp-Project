#include <curses.h>
#include "Map.hpp"


#define MAP_SIZE 23
const int mapRows = MAP_SIZE;
const int mapCols = MAP_SIZE * 2;

int main(int argc, char** argv)
{
    initscr();
    refresh();
    start_color();

    Map map(mapRows, mapCols);

    /*WINDOW* scoreWin = subwin(stdscr, mapHeight/2, (mapWidth / 3 ) * 2, 2, mapWidth + 7);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    box(scoreWin, 0, 0);
    attron(COLOR_PAIR(2));
    wbkgd(scoreWin, COLOR_PAIR(2));

    WINDOW* resultWin = subwin(stdscr, mapHeight/2, (mapWidth / 3 ) * 2, mapHeight/2 + 3 , mapWidth + 7);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    box(resultWin, 0, 0);
    attron(COLOR_PAIR(2));
    wbkgd(resultWin, COLOR_PAIR(2));*/

    refresh();

    getch();
    endwin();

    return 0;
}
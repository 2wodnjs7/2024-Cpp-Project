#include <curses.h>
#include <iostream>
#include "scoreboard.h"

using namespace std;

int main() {
    initscr();
    noecho();
    curs_set(0);

    ScoreBoard scoreboard;

    int length = 5;
    int maxLen = 10;
    int growth = 2;
    int poison = 1;
    int gates = 0;
    int goal = 15;

    scoreboard.update(length, maxLen, growth, poison, gates, goal);
    scoreboard.display();


    endwin();

    return 0;
}

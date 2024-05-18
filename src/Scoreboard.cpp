// [24.05.10.] 조윤주, scoreboard의 변동되는 값을 저장하고 나타낸다.

#include <curses.h>
#include <iostream>
#include "Scoreboard.hpp"

using namespace std;

Score::Score(int height, int width, int y, int x) {
    win = subwin(stdscr, height, width, y, x);
}

void Score::update(int length, int maxLen, int growth, int poison, int gates) {
    currentLength = length;
    maxLength = maxLen;
    growthItems = growth;
    poisonItems = poison;
    useGate = gates;
}

void Score::printBoard() {
    mvwprintw(win, 0, 0, "Score Board");
    mvwprintw(win, 1, 0, "Length: %d", currentLength);
    mvwprintw(win, 2, 0, "Max Length: %d", maxLength);
    mvwprintw(win, 3, 0, "Growth Items: %d", growthItems);
    mvwprintw(win, 4, 0, "Poison Items: %d", poisonItems);
    mvwprintw(win, 5, 0, "Used Gates: %d", useGate);
    wrefresh(win);
}

Mission::Mission(int height, int width, int y, int x) {
    win = subwin(stdscr, height, width, y, x);
}

void Mission::update(int goal, int plus, int minus, int gate) {

    missionGoal = goal;
    missionGrowth = plus;
    missionPoison = minus;
    missionGate = gate;
}

void Mission::achieve() {
    // 미션 달성 시 v 체크 표시
}

void Mission::printBoard() {
    mvwprintw(win, 0, 0, "Mission Board");
    mvwprintw(win, 1, 0, "Goal Length: %d", missionGoal);
    mvwprintw(win, 2, 0, "Growth Items: %d", missionGrowth);
    mvwprintw(win, 3, 0, "Poison Items: %d", missionPoison);
    mvwprintw(win, 4, 0, "Used Gates: %d", missionGate);
    wrefresh(win);
}


int main(void) {
    initscr();
    noecho();
    cbreak();

    Score scoreboard(10, 30, 2, 70);
    Mission missionboard(10, 30, 10, 70);

    int length = 5;
    int maxLen = 10;
    int growth = 2;
    int poison = 1;
    int gates = 0;
    int goal = 10;
    int plus = 5;
    int minus = 2;
    int gate = 1;

    scoreboard.update(length, maxLen, growth, poison, gates);
    missionboard.update(goal, plus, minus, gate);

    scoreboard.printBoard();
    missionboard.printBoard();

    getch();
    endwin();

    return 0;
}
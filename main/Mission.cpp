#include "Mission.hpp"

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
    // �̼� �޼� �� v üũ ǥ��
}

void Mission::printBoard() {
    mvwprintw(win, 0, 0, "Mission Board");
    mvwprintw(win, 1, 0, "Goal Length: %d", missionGoal);
    mvwprintw(win, 2, 0, "Growth Items: %d", missionGrowth);
    mvwprintw(win, 3, 0, "Poison Items: %d", missionPoison);
    mvwprintw(win, 4, 0, "Used Gates: %d", missionGate);
    wrefresh(win);
}
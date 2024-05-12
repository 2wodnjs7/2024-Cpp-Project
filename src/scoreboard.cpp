#include <curses.h>
#include <iostream>

using namespace std;

const int scoreRows = 20;
const int scoreCols = 40;


class ScoreBoard {
private:
    int currentLength;
    int maxLength;
    int growthItems;
    int poisonItems;
    int useGate;
    int missionGoal;
    bool goalAchieved;

public:
    ScoreBoard() {
        currentLength = 0;
        maxLength = 0;
        growthItems = 0;
        poisonItems = 0;
        useGate = 0;
        missionGoal = 0;
        goalAchieved = false;
    }

    void update(int length, int maxLen, int growth, int poison, int gates, int goal) {
        currentLength = length;
        maxLength = maxLen;
        growthItems = growth;
        poisonItems = poison;
        useGate = gates;
        missionGoal = goal;
        goalAchieved = (currentLength >= missionGoal);
    }

    void display() {
        cout << "Score Board\n";
        cout << "B: " << currentLength << " / " << maxLength << "\n";
        cout << "+: " << growthItems << "\n";
        cout << "-: " << poisonItems << "\n";
        cout << "G: " << useGate << "\n\n";
        cout << "Mission\n";
        cout << "G: " << missionGoal << " (" << (goalAchieved ? "v" : " ") << ")\n";
    }
};

int main() {
    initscr();

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

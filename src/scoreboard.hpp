#pragma once

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
    ScoreBoard();

    void update(int length, int maxLen, int growth, int poison, int gates, int goal);
    void display();
};

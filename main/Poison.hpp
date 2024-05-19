#ifndef __POISON__
#define __POISON__

#include <curses.h>
#include <cstdlib>
#include <random>
#include "Map.hpp"

class Poison {
public:
    Poison(Map* map);
    int getCountSpace();
    bool makePoison();
    void setPoison(const int fruit, Point& fruitPoint);
    void deletePoison(); // fruit 제거
    void getPoisonPoint(); // 좌표를 (y,x) 형태로 반환하는 함수 필요
    void isgetPoison(const int, const int, int&);
    //void drawFruit(const int , const int);
    void countTime();
    void eatPoison(); // fruit 먹을 시 점수+1 + delete
    void losePoison(); // 시간 지날 시 delete
    // 과일 생성을 마지막에 해야함.
private:
    int poison, countSpace, timeOfPoison;
    Point poisonPoint;
    Map* thisMap;
    const int LIMIT_TIME = 5;
};

#endif


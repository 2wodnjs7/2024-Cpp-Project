#ifndef __FRUIT__
#define __FRUIT__

#include <curses.h>
#include <cstdlib>
#include <random>
#include "Map.hpp"

class Fruit{
public:
    Fruit(Map* map);
    int getCountSpace();
    bool makeFruit();
    void setFruit(const int fruit, Point& fruitPoint);
    void deleteFruit(); // fruit 제거
    void getFruitPoint(); // 좌표를 (y,x) 형태로 반환하는 함수 필요
    void isgetFruit(const int, const int, int&);
    //void drawFruit(const int , const int);
    void countTime();
    void eatFruit(); // fruit 먹을 시 점수+1 + delete
    void loseFruit(); // 시간 지날 시 delete
    // 과일 생성을 마지막에 해야함.
private:
    int fruit, countSpace, timeOfFruit;
    Point fruitPoint;
    Map* thisMap;
    const int LIMIT_TIME = 5;
};

#endif


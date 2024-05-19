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
    void deleteFruit(); // fruit ����
    void getFruitPoint(); // ��ǥ�� (y,x) ���·� ��ȯ�ϴ� �Լ� �ʿ�
    void isgetFruit(const int, const int, int&);
    //void drawFruit(const int , const int);
    void countTime();
    void eatFruit(); // fruit ���� �� ����+1 + delete
    void loseFruit(); // �ð� ���� �� delete
    // ���� ������ �������� �ؾ���.
private:
    int fruit, countSpace, timeOfFruit;
    Point fruitPoint;
    Map* thisMap;
    const int LIMIT_TIME = 5;
};

#endif


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
    void deletePoison(); // fruit ����
    void getPoisonPoint(); // ��ǥ�� (y,x) ���·� ��ȯ�ϴ� �Լ� �ʿ�
    void isgetPoison(const int, const int, int&);
    //void drawFruit(const int , const int);
    void countTime();
    void eatPoison(); // fruit ���� �� ����+1 + delete
    void losePoison(); // �ð� ���� �� delete
    // ���� ������ �������� �ؾ���.
private:
    int poison, countSpace, timeOfPoison;
    Point poisonPoint;
    Map* thisMap;
    const int LIMIT_TIME = 5;
};

#endif


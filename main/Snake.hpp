/*
Snake: Snake�� ó�� ȣ���Ҷ� ���
addPiece: Snake�� ���̰� ����� �� ���
removePiece: Snake�� ���̰� �پ�� �� ���
tail: ���� ������ ��ġ
head: ���� �Ӹ��� ��ġ
getDirection: ���� �Ӹ��� �����ϰ� �ִ� ����
setDirection: ���� ����
nextHead: ���� �Ӹ��� ��ġ
*/

#ifndef __SNAKE__
#define __SNAKE__

#include <queue>
#include "Point.hpp"
#include "Map.hpp"
 
class Snake
{
public:
    Snake(Map* map);
    void addPiece(Point piece);
    void removePiece();
    Point tail();
    Point head();
    Direction getDirection();
    bool setDirection(Direction d);
    void inGateChangeDirection(Direction d);
    Point nextHead();
private:
    queue<Point> snakeQueue;
    Direction direction;
    Map* thisMap;
    int snakeLength = 0;
};

#endif
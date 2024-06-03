/*
Snake: Snake를 처음 호출할때 사용
addPiece: Snake의 길이가 길어질 때 사용
removePiece: Snake의 길이가 줄어들 때 사용
tail: 현재 꼬리의 위치
head: 현재 머리의 위치
getDirection: 현재 머리가 진행하고 있는 방향
setDirection: 방향 조정
nextHead: 다음 머리의 위치
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
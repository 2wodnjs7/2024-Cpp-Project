#pragma once
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
#include <curses.h>
#include "snakeDraw.hpp"
#include <queue>

enum Direction {
    up,
    down,
    left,
    right
};

class SnakePiece : public snakeDraw
{
public:
    SnakePiece()
    {
        this->x = this->y = 0;
        this->icon = '#';

    }

    SnakePiece(int y, int x)
    {
        this->x = x;
        this->y = y;
        this->icon = '#';
    }
};

class Snake
{
    std::queue<SnakePiece> prev_pieces;
    Direction cur_direction;
public:
    Snake();

    void addPiece(SnakePiece piece);

    void removePiece();

    SnakePiece tail();

    SnakePiece head();

    Direction getDirection();

    void setDirection(Direction d);

    SnakePiece nextHead();
};
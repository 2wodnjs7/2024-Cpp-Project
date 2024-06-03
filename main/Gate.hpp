/*
Gate Ŭ���� : Snake Game�� Gate�� ��Ÿ���� Ŭ����
makeGate() line �� ����
 15		: Wall�� ������ countWall�� ���� 
 17~19	: 0 ~ countWall �� ���� �߻�
 21~27	: gate1, gate2�� ���� �ٸ� ���� ���� 
 29~30	: ���� ��ġ�� Gate�� ����
setGate() : ���� ��ġ�� Gate�� '7'�� �����ϴ� �Լ�
getCountWall : ���� Map->mapArray[][]�� '1'�� ������ ��ȯ�ϴ� �Լ�
deleteGate() : ���� Map->mapArray[][]�� '7'�� '1'�� �����ϴ� �Լ�
*/

#ifndef __GATE__
#define __GATE__

#include <iostream>
#include <random>
#include "Point.hpp"
#include "Map.hpp"

const int GATE_TIME = 10;

class Gate
{
public:
	Gate(Map* map);
	void makeGate();
	void setGate(const int gate, Point &gatePoint);
	Direction inGate(Point& gatePoint, Direction diretion);
	bool checkRange(Point point);
	int getCountWall();
	void deleteGate();
	void resetGate();
private:
	int resetTime = 0;
	int countWall = 0;
	int gate1 = 0;
	int gate2 = 0;
	Point gate1Point;
	Point gate2Point;
	Map* thisMap;
};

#endif
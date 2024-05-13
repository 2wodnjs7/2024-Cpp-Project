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
#include "Map.hpp"

class Gate
{
public:
	Gate(Map* Map);
	void makeGate();
	void setGate(int gate);
	int getCountWall();
	void deleteGate();
private:
	int countWall = 0;
	int gate1 = 0;
	int gate2 = 0;
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };
	Map* thisMap;
};

#endif
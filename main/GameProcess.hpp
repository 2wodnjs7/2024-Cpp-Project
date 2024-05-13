/*
GameProcess Ŭ����
- ���� Map, Gate Ŭ������ ���� Ŭ����, ���� Snake, Fruit, Poison �߰� ����
������
- ���޵� height, width�� ���� map ��ü �ʱ�ȭ
- map ��ü�� ���ڷ� �޴� gate ��ü �ʱ�ȭ
- gameOver ������� �ʱ�ȭ
reDraw() : map ��ü�� refreshMap() �Լ� ���
tick() : ������ �����ð��� ����ϴ� �Լ�
makeGate() : gate ��ü�� makeGate() �Լ� ���
deleteGate() : gate ��ü�� deleteGate() �Լ� ���
isOver() : gameOver ������ ���� ( true�� ����, false�� ��� ���� )
*/

#ifndef __GP__
#define __GP__
#include <windows.h>
#include "Map.hpp"
#include "Gate.hpp"

class GameProcess
{
public:
	GameProcess(const int height, const int width);
	void reDraw();
	void tick(const int time);
	void makeGate();
	void deleteGate();
	bool isOver();
private:
	Map* map;
	Gate* gate;
	//Snake* snake; - ���� �߰� ����
	//Fruit* fruit; - ���� �߰� ����
	//Poison* poison; - ���� �߰� ����
	bool gameOver;
};

#endif
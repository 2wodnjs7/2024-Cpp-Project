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
#include "Snake.hpp"
#include "Fruit.hpp"
#include "Poison.hpp"
#include "Gate.hpp"
#include "Score.hpp"
#include "Mission.hpp"


class GameProcess
{
public:
	GameProcess(const int height, const int width);
	void init();
	void initSnake();
	void reduceSnake();
	void inputGame();
	void updateGame();
	void reDraw();
	void setTick(const int time);
	bool checkFailed(const Point& next);
	bool checkFruit(const Point& next);
	bool checkPoison(const Point& next);
	bool isOver();
private:
	int snakeLength = 3;
	Map* map;
	Score* score;
	Mission* mission;
	Snake* snake;
	Fruit* fruit;
	Poison* poison;
	Gate* gate;
	bool gameOver;
};

#endif
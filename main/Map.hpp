/*
Map Ŭ���� : Snake Game ȭ���� ǥ���ϴ� Ŭ����, Window Ŭ������ ��ӹ���
getMap() : mapArray[x][y]�� ���� �����ϴ� �Լ�
setMap() : mapArray[x][y]�� ���� ����/�����ϴ� �Լ�
addch() : curses�� mvaddch()�� ���� Map->win�� y, x��ġ�� ch�� ����ϴ� �Լ�
setMapFirst() : �����ڿ��� �ܺ� txt�� ���� �ҷ��� mapArray�� �����ϴ� �Լ�
refreshMap() : ���� ����� ������ ȭ�鿡 �ٽ� ���� ����ϴ� �Լ�
mapArray[][] : Snake Game ȭ���� ���� �����ϴ� ��� ����
*/

#ifndef __MAP__
#define __MAP__

#include <fstream>
#include "Window.hpp"
#include "Point.hpp"

using namespace std;

const char mapTxt[] = "map/mapEasy.txt";

class Map : public Window
{
public:
	Map(const int height, const int width);
	void init();
	chtype getInput();
	char getMap(const int y, const int x);
	char getMap(const Point point);
	void setMap(const int y, const int x, const char c);
	void setMap(const Point point, const char ch);
	void addCh(const int y, const int x, const char ch);
	void addStr(const int y, const int x, const char* ch);
	void setMapFirst();
	void refreshMap();
	bool checkMap(const Point point, const char ch);
	void setTick(const int time);
	
private:
	char mapArray[MAP_SIZE][MAP_SIZE];
};

#endif
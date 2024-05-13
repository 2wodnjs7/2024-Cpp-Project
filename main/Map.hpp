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

#include "Window.hpp"
#include <fstream>

#define MAP_SIZE 23

using namespace std;

class Map : public Window
{
public:
	Map(const int height, const int width);
	char getMap(const int x, const int y);
	void setMap(const int x, const int y, const char c);
	void addCh(const int y, const int x, const char ch);
	void addStr(const int y, const int x, const char* ch);
	void setMapFirst();
	void refreshMap();
private:
	char mapArray[MAP_SIZE][MAP_SIZE];
};

#endif
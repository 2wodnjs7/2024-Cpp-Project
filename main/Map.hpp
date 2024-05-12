/*
Map Ŭ���� : Snake Game ȭ���� ǥ���ϴ� Ŭ����, Window Ŭ������ ��ӹ���
getMap() : mapArray[x][y]�� ���� �����ϴ� �Լ�
setMap() : mapArray[x][y]�� ���� ����/�����ϴ� �Լ�
addch() : curses�� mvaddch()�� ���� Map->win�� y, x��ġ�� ch�� ����ϴ� �Լ�
setMapFirst() : �����ڿ��� �ܺ� txt�� ���� �ҷ��� mapArray�� �����ϴ� �Լ�
refreshMap() : ���� ����� ������ ȭ�鿡 �ٽ� ���� ����ϴ� �Լ�
mapArray[][] : Snake Game ȭ���� ���� �����ϴ� ��� ����
*/

#pragma once
#include "Window.hpp"
#include <fstream>
#include "Gate.hpp"

#define MAP_SIZE 23

using namespace std;

class Map : public Window
{
public:
	Map(int height, int width);
	char getMap(int x, int y);
	void setMap(int x, int y, char c);
	void addCh(int y, int x, char ch);
	void setMapFirst();
	void refreshMap();
private:
	char mapArray[MAP_SIZE][MAP_SIZE];
};
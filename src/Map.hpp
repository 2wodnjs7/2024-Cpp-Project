/*
Map 클래스 : Snake Game 화면을 표시하는 클래스, Window 클래스를 상속받음
getMap() : mapArray[x][y]의 값을 리턴하는 함수
setMap() : mapArray[x][y]의 값을 설정/변경하는 함수
addch() : curses의 mvaddch()를 통해 Map->win의 y, x위치에 ch를 출력하는 함수
setMapFirst() : 생성자에서 외부 txt의 값을 불러와 mapArray에 저장하는 함수
refreshMap() : 맵이 변경될 때마다 화면에 다시 전부 출력하는 함수
mapArray[][] : Snake Game 화면을 값을 저장하는 멤버 변수
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
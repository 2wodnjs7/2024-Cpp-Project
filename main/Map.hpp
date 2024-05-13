/*
Map 클래스 : Snake Game 화면을 표시하는 클래스, Window 클래스를 상속받음
getMap() : mapArray[x][y]의 값을 리턴하는 함수
setMap() : mapArray[x][y]의 값을 설정/변경하는 함수
addch() : curses의 mvaddch()를 통해 Map->win의 y, x위치에 ch를 출력하는 함수
setMapFirst() : 생성자에서 외부 txt의 값을 불러와 mapArray에 저장하는 함수
refreshMap() : 맵이 변경될 때마다 화면에 다시 전부 출력하는 함수
mapArray[][] : Snake Game 화면을 값을 저장하는 멤버 변수
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
/*
Window 클래스 : Map 클래스, Score 클래스, Mission 클래스 의 부모 클래스
init() : curses의 initsrc() 함수를 멤버 함수로 정의
startColor() : curses의 start_color() 함수를 멤버 함수로 정의
endWin() : curses의 endwin() 함수를 멤버 함수로 정의
addCh() : mvwaddch()로 win에 정해진 위치에 한 글자 출력하는 함수
addStr() : mvwaddStr()로 win에 정해진 위치에 여러 글자 출력하는 함수
WINDOW* win : curses의 한 윈도우인 멤버 변수
*/ 

#ifndef __WIN__
#define __WIN__

#include <curses.h>
#include <iostream>

#define MAP_SIZE 25

using namespace std;

class Window
{
public:
	void startColor();
	void endWin();
	void clear();
	void addCh(int y, int x, char ch);
	void addStr(int y, int x, const char* str);
	void refresh();
protected:
	WINDOW* win;
};

#endif
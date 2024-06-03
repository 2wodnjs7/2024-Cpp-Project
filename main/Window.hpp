/*
Window Ŭ���� : Map Ŭ����, Score Ŭ����, Mission Ŭ���� �� �θ� Ŭ����
init() : curses�� initsrc() �Լ��� ��� �Լ��� ����
startColor() : curses�� start_color() �Լ��� ��� �Լ��� ����
endWin() : curses�� endwin() �Լ��� ��� �Լ��� ����
addCh() : mvwaddch()�� win�� ������ ��ġ�� �� ���� ����ϴ� �Լ�
addStr() : mvwaddStr()�� win�� ������ ��ġ�� ���� ���� ����ϴ� �Լ�
WINDOW* win : curses�� �� �������� ��� ����
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
#define MAP_SIZE 23
#include <curses.h>
#include <fstream>
#include <iostream>
#include "Gate.hpp"

using namespace std;

class Map
{
public:
	Map(int height, int width);
	void init();
	void clear();
	char getMap(int x, int y);
	void setMap(int x, int y, char c);
	void addCh(int y, int x, char ch);
	void setMapFirst();
	void refresh();
	void refreshMap();
private:
	WINDOW* mapWin;
	char mapArray[MAP_SIZE][MAP_SIZE];
};
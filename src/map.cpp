#include <fstream>
#include <curses.h>
#include "map.hpp"
#include <iostream>

using namespace std;

Map::Map(int height, int width)
{
	this->mapWin = subwin(stdscr, height, width, 2, 4);
	this->setMapFirst();
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	wbkgd(this->mapWin, COLOR_PAIR(2));
	this->refreshMap();
	wrefresh(this->mapWin);
}

void Map::init()
{
	this->clear();
	this->refresh();
}

void Map::addCh(int y, int x, char ch)
{
	mvwaddch(this->mapWin, y, x, ch);
}

void Map::clear()
{
	wclear(this->mapWin);
}

void Map::refresh()
{
	wrefresh(this->mapWin);
}

void Map::setMapFirst()
{
	ifstream ifs;
	ifs.open("mapEasy.txt");
	for (int i = 0; i < 23; i++)
	{
		int a;
		string st;
		ifs >> st;
		for (int j = 0; j < 23; j++)
		{
			this->mapArray[i][j] = st[j];
		}
	}
	ifs.close();
}

void Map::refreshMap()
{
	for (int i = 0; i < 23; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			wmove(mapWin, i, j*2);
			if (this->mapArray[i][j] == '2' || this->mapArray[i][j] == '1')
				waddch(mapWin, 'бр');
			else
				waddch(mapWin, ' ');
		}
	}
	this->refresh();
}


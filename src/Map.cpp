#pragma once
#include "Map.hpp"

using namespace std;

Map::Map(int height, int width)
{
	this->win = subwin(stdscr, height, width, 2, 4);
	this->setMapFirst();
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	wbkgd(this->win, COLOR_PAIR(2));
	Gate Gate(this->mapArray);
	this->refreshMap(); 
}


char Map::getMap(int x, int y)
{
	return this->mapArray[x][y];
}

void Map::setMap(int x, int y, char c)
{
	this->mapArray[x][y] = c;
}

void Map::addCh(int y, int x, char ch)
{
	mvwaddch(this->win, y, x, ch);
}

void Map::setMapFirst()
{
	ifstream ifs;
	ifs.open("mapNormal.txt");
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
			if (this->mapArray[i][j] == '2' || this->mapArray[i][j] == '1')
			{
				this->addCh(i, j * 2, '#');
			}
			else if (this->mapArray[i][j] == '7')
			{
				this->addCh(i, j * 2, 'G');
			}
			else
			{
				//this->addCh(i, j*2, '0');
			}
		}
	}
	this->refresh();
}

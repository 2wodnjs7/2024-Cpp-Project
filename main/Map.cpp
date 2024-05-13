#include "Map.hpp"

Map::Map(const int height, const int width)
{
	this->win = subwin(stdscr, height, width, 2, 4);
	this->setMapFirst();
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	wbkgd(this->win, COLOR_PAIR(2));
	this->refreshMap(); 
}


char Map::getMap(const int x, const int y)
{
	return this->mapArray[x][y];
}

void Map::setMap(const int x, const int y, const char c)
{
	this->mapArray[x][y] = c;
}

void Map::addCh(const int y, const int x, const char ch)
{
	mvwaddch(this->win, y, x, ch);
}

void Map::addStr(const int y, const int x, const char* ch)
{
	mvwaddstr(this->win, y, x, ch);
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
			this->setMap(i, j, st[j]);
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
			if (this->getMap(i,j) == '2' || this->getMap(i, j) == '1')
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

//void Map::makeGate()
//{
//	gate->makeGate();
//}
//
//void Map::deleteGate()
//{
//	gate->deleteGate();
//}
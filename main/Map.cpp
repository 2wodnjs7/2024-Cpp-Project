#include "Map.hpp"

Map::Map(const int height, const int width)
{
	this->win = subwin(stdscr, height, width, 2, 4);
	this->setMapFirst();
}

void Map::init()
{
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	wbkgd(this->win, COLOR_PAIR(2));
	this->refreshMap();
	keypad(this->win, true);
}

chtype Map::getInput()
{
	return wgetch(this->win);
}

char Map::getMap(const int y, const int x)
{
	return this->mapArray[y][x];
}

char Map::getMap(const Point point)
{
	return this->mapArray[point.getY()][point.getX()];
}

void Map::setMap(const int y, const int x, const char c)
{
	this->mapArray[y][x] = c;
}

void Map::setMap(const Point point, const char ch)
{
	this->mapArray[point.getY()][point.getX()] = ch;
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
	ifs.open("test.txt");
	for (int i = 0; i < MAP_SIZE; i++)
	{
		int a;
		string st;
		ifs >> st;
		for (int j = 0; j < MAP_SIZE; j++)
		{
			this->setMap(i, j, st[j]);
		}
	}
	ifs.close();
}

void Map::refreshMap()
{
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			switch (this->getMap(i, j))
			{
			case '0':
				this->addCh(i, j * 2, ' ');
				break;
			case '1':
				this->addCh(i, j * 2, '#');
				break;
			case '2':
				this->addCh(i, j * 2, '#');
				break;
			case '3':
				this->addCh(i, j * 2, 'H');
				break;
			case '4':
				this->addCh(i, j * 2, 'B');
				break;
			case '5':
				this->addCh(i, j * 2, 'F');
				break;
			case '6':
				this->addCh(i, j * 2, 'P');
				break;
			case '7':
				this->addCh(i, j * 2, 'G');
				break;
			}
		}
	}
	this->refresh();
}

bool Map::checkMap(const Point point, const char ch)
{
	if (this->getMap(point.getY(), point.getX()) == ch)
		return true;
	else
		return false;
}

void Map::setTick(int time)
{
	wtimeout(this->win, time);
}
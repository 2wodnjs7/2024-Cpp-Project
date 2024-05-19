#include "GameProcess.hpp"

GameProcess::GameProcess(const int height, const int width)
{
	this->map = new Map(height, width);
	this->score = new Score(10, 30, 2, 70);
	this->mission = new Mission(10, 30, 10, 70);
	this->snake = new Snake(this->map);
	this->initSnake();
	this->fruit = new Fruit(this->map);
	this->poison = new Poison(this->map);
	this->gate = new Gate(this->map);
	this->gameOver = false;
}

void GameProcess::init()
{
	map->init();

	fruit->makeFruit();

	poison->makePoison();

	map->refreshMap();
}

void GameProcess::initSnake()
{
	snake->setDirection(_right);
	Point next = Point(1, 1);
	map->setMap(next, '4');
	snake->addPiece(next);

	next = snake->nextHead();
	map->setMap(next, '4');
	snake->addPiece(next);

	next = snake->nextHead();
	map->setMap(next, '3');
	snake->addPiece(next);
}

void GameProcess::reduceSnake()
{
	map->setMap(snake->tail(), '0');
	snake->removePiece();
}

void GameProcess::inputGame()
{
	chtype input = map->getInput();
	switch (input)
	{
	case KEY_UP:
		if (snake->setDirection(_up))
		{
			this->gameOver = true;
			return;
		}
		break;
	case KEY_RIGHT:
		if (snake->setDirection(_right))
		{
			this->gameOver = true;
			return;
		}
		break;
	case KEY_DOWN:
		if (snake->setDirection(_down))
		{
			this->gameOver = true;
			return;
		}
		break;
	case KEY_LEFT:
		if (snake->setDirection(_left))
		{
			this->gameOver = true;
			return;
		}
		break;
	default:
		break;
	}
}

void GameProcess::updateGame()
{
	Point next = snake->nextHead();
	if (checkFailed(next))
		return;
	map->setMap(snake->head(), '4');
	snake->addPiece(next);
	if (!(checkFruit(next)))
		reduceSnake();
	if (checkPoison(next))
		reduceSnake();
}

void GameProcess::reDraw()
{
	map->refreshMap();
}

void GameProcess::setTick(const int time)
{
	map->setTick(time);
}

bool GameProcess::checkFailed(const Point& next)
{
	if (map->checkMap(next, '1') 
	||  map->checkMap(next, '2') 
	||  map->checkMap(next, '3')
	||	map->checkMap(next, '4'))
	{
		this->gameOver = true;
		return true;
	}
	return false;
}

bool GameProcess::checkFruit(const Point& next)
{
	if (map->checkMap(next, '5'))
	{
		snakeLength++;
		if (fruit->makeFruit())
		{
			this->gameOver = true;
			return false;
		}
		score->updateLength('+');
		return true;
	}
	return false;
}

bool GameProcess::checkPoison(const Point& next)
{
	if (map->checkMap(next, '6'))
	{
		snakeLength--;
		if (poison->makePoison() || snakeLength < 3)
		{
			this->gameOver = true;
			return false;
		}
		map->setMap(next, '3');
		score->updateLength('-');
		return true;
	}
	map->setMap(next, '3');
	return false;
}


bool GameProcess::isOver()
{
	return this->gameOver;
}
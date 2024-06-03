#include "GameProcess.hpp"

GameProcess::GameProcess(const int height, const int width)
{
	this->map = new Map(height, width);
	this->gameTimer = new GameTimer(5, 28, 2, 65);
	this->score = new Score(11, 28, 8, 65);
	this->mission = new Mission(11, 28, 18, 65);
	this->snake = new Snake(this->map);
	this->initSnake();
	for(int i=0;i<5;i++)
	{
		this->fruit[i] = new Fruit(this->map);
		this->poison[i] = new Poison(this->map);
	}
	this->gate = new Gate(this->map);
	this->gameOver = false;
}

void GameProcess::init()
{
	map->init();
	initCountSpace();
	for (int i = 0; i < 5; i++)
	{
		fruit[i]->makeItem(countSpace, '5');
		poison[i]->makeItem(countSpace, '6');
	}
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

void GameProcess::initCountSpace()
{
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if (map->getMap(i, j) == '0')
				countSpace++;
		}
	}
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
	gameTimer->upGameTime();
	Point next = snake->nextHead();
	if (checkFailed(next))
		return;
	map->setMap(snake->head(), '4');
	checkGate(next);
	snake->addPiece(next);
	if (!(checkFruit(next)))
		reduceSnake();
	if (checkPoison(next))
		reduceSnake();
	checkMission();
	checkTick();
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
		for (int i = 0; i < 5; i++)
		{
			if (fruit[i]->getPoint() == next)
			{
				if (fruit[i]->makeItem(countSpace, '5'))
				{
					this->gameOver = true;
					return false;
				}
			}
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

		for (int i = 0; i < 5; i++)
		{
			if (poison[i]->getPoint() == next)
			{
				if (poison[i]->makeItem(countSpace, '6') || snakeLength < 3)
				{
					this->gameOver = true;
					return false;
				}
			}
		}
		map->setMap(next, '3');
		score->updateLength('-');
		return true;
	}
	map->setMap(next, '3');
	return false;
}

void GameProcess::checkGate(Point& next)
{
	if (map->checkMap(next, '7'))
	{
		inGating = true;
		snake->inGateChangeDirection(gate->inGate(next, snake->getDirection()));
		score->updateUseGate();
	}
}

void GameProcess::checkTick()
{
	for (int i = 0; i < 5; i++)
	{
		fruit[i]->resetItem(countSpace, '5');
		poison[i]->resetItem(countSpace, '6');
	}
	if(inGating)
	{
		if (gateInSnake < snakeLength)
		{
			gateInSnake++;
		}
		else
		{
			gateInSnake = 1;
			inGating = false;
		}
	}
	else
	{
		gate->resetGate();
	}
}

void GameProcess::checkMission()
{
	mission->checkLength(score->getMaxLength());
	mission->checkGrowth(score->getGrowthItems());
	mission->checkPoison(score->getPoisonItems());
	mission->checkUsedGates(score->getUsedGates());
	if (mission->checkMission())
	{
		this->gameOver = true;
		this->gameClearState = true;
	}
}

bool GameProcess::isOver()
{
	return this->gameOver;
}

bool GameProcess::gameClear()
{
	return this->gameClearState;
}

void GameProcess::finish()
{
	if (gameClear())
	{
		WINDOW* win = subwin(stdscr, 11, 93, 9, 4);
		wclear(win);
		box(win, 0, 0);
		mvwaddstr(win, 2, 3, " ######      ###    ##     ## ########     ######  ##       ########    ###    ######## ");
		mvwaddstr(win, 3, 3, "##    ##    ## ##   ###   ### ##          ##    ## ##       ##         ## ##   ##     ##");
		mvwaddstr(win, 4, 3, "##         ##   ##  #### #### ##          ##       ##       ##        ##   ##  ##     ##");
		mvwaddstr(win, 5, 3, "##   #### ##     ## ## ### ## ######      ##       ##       ######   ##     ## ######## ");
		mvwaddstr(win, 6, 3, "##    ##  ######### ##     ## ##          ##       ##       ##       ######### ##   ##  ");
		mvwaddstr(win, 7, 3, "##    ##  ##     ## ##     ## ##          ##    ## ##       ##       ##     ## ##    ## ");
		mvwaddstr(win, 8, 3, " ######   ##     ## ##     ## ########     ######  ######## ######## ##     ## ##     ##");
		wrefresh(win);
	}
	else
	{
		WINDOW* win = subwin(stdscr, 11, 85, 9, 7);
		wclear(win);
		box(win, 0, 0);
		mvwaddstr(win, 2, 3, " ######      ###    ##     ## ########     #######  ##     ## ######## ######## ");
		mvwaddstr(win, 3, 3, "##    ##    ## ##   ###   ### ##          ##     ## ##     ## ##       ##     ##");
		mvwaddstr(win, 4, 3, "##         ##   ##  #### #### ##          ##     ## ##     ## ##       ##     ##");
		mvwaddstr(win, 5, 3, "##   #### ##     ## ## ### ## ######      ##     ## ##     ## ######   ######## ");
		mvwaddstr(win, 6, 3, "##    ##  ######### ##     ## ##          ##     ##  ##   ##  ##       ##   ##  ");
		mvwaddstr(win, 7, 3, "##    ##  ##     ## ##     ## ##          ##     ##   ## ##   ##       ##    ## ");
		mvwaddstr(win, 8, 3, " ######   ##     ## ##     ## ########     #######     ###    ######## ##     ##");
		wrefresh(win);
	}	
}
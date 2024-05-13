#include "GameProcess.hpp"

GameProcess::GameProcess(const int height, const int width)
{
	this->map = new Map(height, width);
	this->gate = new Gate(this->map);
	this->gameOver = false;
}

void GameProcess::reDraw()
{
	map->refreshMap();
}

void GameProcess::tick(const int time)
{
	Sleep(time*1000);
}

void GameProcess::makeGate()
{
	gate->makeGate();
}

void GameProcess::deleteGate()
{
	gate->deleteGate();
}

bool GameProcess::isOver()
{
	return this->gameOver;
}
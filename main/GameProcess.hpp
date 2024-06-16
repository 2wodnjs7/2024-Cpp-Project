#ifndef __GP__
#define __GP__
#include "Map.hpp"
#include "Snake.hpp"
#include "Fruit.hpp"
#include "Poison.hpp"
#include "Gate.hpp"
#include "GameTimer.hpp"
#include "Score.hpp"
#include "Mission.hpp"


class GameProcess
{
public:
	GameProcess(const int height, const int width);
	void init();
	void initNextStage();
	void deleteGame();
	void initSnake();
	void initCountSpace();
	void reduceSnake();
	void inputGame();
	void updateGame();
	void reDraw();
	void setTick(const int time);
	bool checkFailed(const Point& next);
	bool checkFruit(const Point& next);
	bool checkPoison(const Point& next);
	void checkGate(Point& next);
	void checkTick();
	void checkMission();
	bool checkOver();
	bool isOver();
	bool gameClear();
	void finish();
private:
	int snakeLength;
	Map* map;
	GameTimer* gameTimer;
	Score* score;
	Mission* mission;
	Snake* snake;
	Fruit* fruit[5];
	Poison* poison[5];
	Gate* gate;
	int gateInSnake;
	bool inGating;
	bool gameOver;
	int countSpace;
	bool gameClearState;
};

#endif
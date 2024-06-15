/*
GameProcess 클래스
- 현재 Map, Gate 클래스를 지닌 클래스, 향후 Snake, Fruit, Poison 추가 예정
생성자
- 전달된 height, width를 통해 map 객체 초기화
- map 객체를 인자로 받는 gate 객체 초기화
- gameOver 멤버변수 초기화
reDraw() : map 객체의 refreshMap() 함수 사용
tick() : 게임의 지연시간을 사용하는 함수
makeGate() : gate 객체의 makeGate() 함수 사용
deleteGate() : gate 객체의 deleteGate() 함수 사용
isOver() : gameOver 변수를 리턴 ( true면 종료, false면 계속 진행 )
*/

#ifndef __GP__
#define __GP__
#include "Map.hpp";
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
#include "Gate.hpp"

Gate::Gate(Map* map) : thisMap(map)
{
	this->countWall = getCountWall();
	this->makeGate();
}

void Gate::makeGate()
{
	resetTime = 1;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, this->countWall);

	
	this->gate1 = dis(gen);
	while (this->gate2 == 0)
	{
		this->gate2 = dis(gen);
		if (this->gate1 == this->gate2)
			this->gate2 = 0;
	}
	this->setGate(this->gate1, gate1Point);
	this->setGate(this->gate2, gate2Point);
}

void Gate::setGate(const int gate, Point& gatePoint)
{
	int cnt = 0;
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			if (thisMap->getMap(i, j)=='1')
			{
				if (cnt == gate)
				{
					gatePoint = Point(i, j);
					thisMap->setMap(gatePoint, '7');
					return;
				}
				else
					cnt++;
			}
		}
	}
}

Direction Gate::inGate(Point& gatePoint, Direction direction)
{
	Point next;
	if (gate1Point == gatePoint)
		next = gate2Point;
	else
		next = gate1Point;

	Point a = next.nextPoint(direction);
	if (checkRange(a))
	{
		gatePoint = a;
		return direction;
	}

	Direction secondDirection = returnDirection((direction + 1) % 4);
	a = next.nextPoint(secondDirection);
	if (checkRange(a))
	{
		gatePoint = a;
		return secondDirection;
	}

	Direction thirdDirection = returnDirection((direction - 1 + 4) % 4);
	a = next.nextPoint(thirdDirection);
	if (checkRange(a ))
	{
		gatePoint = a;
		return thirdDirection;
	}

	Direction fourthDirection = returnDirection((direction - 2 + 4) % 4);
	a = next.nextPoint(fourthDirection);
	if (checkRange(a))
	{
		gatePoint = a;
		return fourthDirection;
	}
}

bool Gate::checkRange(Point point)
{
	int x = point.getX();
	int y = point.getY();
	if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE || thisMap->getMap(point) != '0')
		return false;
	else
		return true;
}


int Gate::getCountWall()
{
	int countWall = 0;
	for (int i = 0; i < 23; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			if (thisMap->getMap(i,j) == '1')
				countWall++;
		}
	}
	return countWall;
}

void Gate::deleteGate()
{
	this->gate1 = 0;
	this->gate2 = 0;
	thisMap->setMap(this->gate1Point, '1');
	thisMap->setMap(this->gate2Point, '1');
}

void Gate::resetGate() {
	if (resetTime < GATE_TIME)
		resetTime++;
	else
	{
		deleteGate();
		makeGate();
	}
}
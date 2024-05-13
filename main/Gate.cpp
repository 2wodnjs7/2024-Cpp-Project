#include "Gate.hpp"

Gate::Gate(Map* map) : thisMap(map)
{
	this->makeGate();
}

void Gate::makeGate()
{
	this->countWall = getCountWall();

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

	this->setGate(this->gate1);
	this->setGate(this->gate2);
}

void Gate::setGate(int gate)
{
	int cnt = 0;
	for (int i = 0; i < 23; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			if (thisMap->getMap(i,j)=='1')
				if (cnt == gate)
				{
					thisMap->setMap(i, j, '7');
					return;
				}
				else
					cnt++;
		}
	}
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
	for (int i = 0; i < 23; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			if (thisMap->getMap(i, j) == '7')
				thisMap->setMap(i, j, '1');
		}
	}
}
#pragma once
#include "Gate.hpp"
#include <iostream>
#include <random>

using namespace std;

Gate::Gate(char mapArray[23][23])
{
	this->makeGate(mapArray);
}

void Gate::makeGate(char mapArray[23][23])
{
	this->countWall = getCountWall(mapArray);
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
	this->setGate(mapArray, this->gate1);
	this->setGate(mapArray, this->gate2);
}

int Gate::getCountWall(char mapArray[23][23])
{
	int countWall = 0;
	for (int i = 0; i < 23; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			if (mapArray[i][j] == '1')
				countWall++;
		}
	}
	return countWall;
}

void Gate::setGate(char mapArray[23][23],int gate)
{
	int cnt = 0;
	for (int i = 0; i < 23; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			if (mapArray[i][j] == '1')
				if (cnt == gate)
				{
					mapArray[i][j] = '7';
					return;
				}
				else
					cnt++;
		}
	}
}

void Gate::deleteGate(char mapArray[23][23])
{
	for (int i = 0; i < 23; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			if (mapArray[i][j] == '7')
				mapArray[i][j] = '1';
		}
	}
}
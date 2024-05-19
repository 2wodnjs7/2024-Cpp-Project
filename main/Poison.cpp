#include "Poison.hpp"

Poison::Poison(Map* map) : thisMap(map)
{
    countSpace = getCountSpace() - 1;
}

int Poison::getCountSpace() {
    int countSpace = 0;
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (thisMap->getMap(i, j) == '0')
                countSpace++;
        }
    }
    return countSpace;
}

bool Poison::makePoison() {
    if (countSpace == 0)
        return true;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, countSpace - 1);
    poison = dis(gen); // 0중에서만 작동하게
    setPoison(poison, poisonPoint);
    timeOfPoison = 0;
    return false;
}

void Poison::setPoison(const int poison, Point& poisonPoint) {
    int cnt = 0;
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {

            if (thisMap->getMap(i, j) == '0')
            {
                if (cnt == poison)
                {
                    poisonPoint = Point(i, j);
                    thisMap->setMap(poisonPoint, '6');
                    countSpace--;
                    return;
                }
                else
                    cnt++;
            }
        }
    }
}

void Poison::deletePoison()
{
    poison = 0;
    thisMap->setMap(poisonPoint, '0');
}

void Poison::getPoisonPoint() {

}
/*
void Fruit::isgetFruit(const int y, const int x, int &score){
    if(x == fruit && y == FruitY){
        score++; // 이후 score 연동 필요
        makeFruit();
    }
}*/

void Poison::countTime() {
    ++timeOfPoison;
}

void Poison::losePoison() {
    if (timeOfPoison < LIMIT_TIME) countTime();
    else deletePoison();
}
/*
void Fruit::drawFruit(const int y, const int x){
    if(x == fruit && y == FruitY){
        mvprintw(y, x, "@");
    }
}
*/
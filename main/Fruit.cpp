#include "Fruit.hpp"

Fruit::Fruit(Map* map) : thisMap(map)
{
    countSpace = getCountSpace();
}

int Fruit::getCountSpace() {
    int countSpace = 0;
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (thisMap->getMap(i, j) == '0')
                countSpace++;
        }
    }
    return countSpace;
}

bool Fruit::makeFruit() {
    if (countSpace == 0)
        return true;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, countSpace-1);
    fruit = dis(gen); // 0중에서만 작동하게
    setFruit(fruit, fruitPoint);
    timeOfFruit = 0;
    return false;
}

void Fruit::setFruit(const int fruit, Point& fruitPoint) {
    int cnt = 0;
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {

            if (thisMap->getMap(i, j) == '0')
            {
                //cout << countSpace << ' ' << fruit << ' ' << cnt << ' ' << i << ' ' << j << endl;
                if (cnt == fruit)
                {
                    fruitPoint = Point(i, j);
                    thisMap->setMap(fruitPoint, '5'); //fruit num
                    countSpace--;
                    return;
                }
                else
                    cnt++;
            }
        }
    }
}

void Fruit::deleteFruit()
{
    fruit = 0;
    thisMap->setMap(fruitPoint, '0');
}

void Fruit::getFruitPoint() {

}
/*
void Fruit::isgetFruit(const int y, const int x, int &score){
    if(x == fruit && y == FruitY){
        score++; // 이후 score 연동 필요
        makeFruit();
    }
}*/

void Fruit::countTime() {
    ++timeOfFruit;
}

void Fruit::loseFruit() {
    if (timeOfFruit < LIMIT_TIME) countTime();
    else deleteFruit();
}
/*
void Fruit::drawFruit(const int y, const int x){
    if(x == fruit && y == FruitY){
        mvprintw(y, x, "@");
    }
}
*/
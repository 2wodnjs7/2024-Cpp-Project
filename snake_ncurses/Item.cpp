#include "Item.hpp"

Item::Item(Map* map) : thisMap(map)
{
	point = Point(1, 1);
}

Point& Item::getPoint()
{
	return point;
}

bool Item::makeItem(int& countSpace, const char ch)
{
    if (countSpace == 0)
        return true;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, countSpace - 1);
    item = dis(gen); // 0중에서만 작동하게
    setItem(item, point, countSpace, ch);
    resetTime = 1;
    return false;
}

void Item::setItem(const int item, Point& point, int& countSpace, const char ch) {
    int cnt = 0;
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            if (thisMap->getMap(i, j) == '0')
            {
                if (cnt == item)
                {
                    point = Point(i, j);
                    thisMap->setMap(point, ch);
                    countSpace--;
                    return;
                }
                else
                    cnt++;
            }
        }
    }
}

void Item::deleteItem()
{
    item = 0;
    thisMap->setMap(point, '0');
}

void Item::resetItem(int& countSpace, const char ch) {
    if (resetTime < ITEM_TIME)
        resetTime++;
    else
    {
        deleteItem();
        countSpace++;
        makeItem(countSpace, ch);
    }
}
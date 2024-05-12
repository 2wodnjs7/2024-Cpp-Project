// snake가 먹을 수 있는 items
// fruit, poison
// set_ : 초기 설정 혹은 각 item을 초기화 시 사용
// isget_ : snake가 item을 먹었는 지 확인하는 logic에 사용
// draw_ : draw시 item print
//
#include "Map.hpp"
#include "items.hpp"
#include <ncurses.h>
#include <cstdlib>
using namespace std;

fruit::fruit();
fruit::setfruit(){ 
    fruitX = (rand() % MAP_SIZE + 1);
    fruitY = (rand() % MAP_SIZE + 1);
}
fruit::isgetfruit(){
    if(x == fruitX && y == fruitY){
        score++;
        setfruit();
    }
}
fruit::drawfruit(const int y, const int x){
    if(x == fruitX && y == fruitY){
        mvprintw(y, x, "@");
    }
}

poison::poison();
poison::setpoison(){
    poisonX = (rand() % MAP_SIZE + 1);
    poisonY = (rand() % MAP_SIZE + 1);
}
poison::isgetpoison(){
    if(x == poisonX && y == poisonY){
        score--;
        setpoison();
    }
}
posion::drawpoison(const int y, const int x){
    if(x == poisonX && y == poisonY){
        mvprintw(y, x, "#");
    }
}
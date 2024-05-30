// snake가 먹을 수 있는 items
// Fruit, Poison
// set_ : 초기 설정 혹은 각 item을 초기화 시 사용
// isget_ : snake가 item을 먹었는 지 확인하는 logic에 사용
// draw_ : draw시 item print
// + 틱 구현(delete)

#include "Items.hpp"

Items::Items(Map* map) : thisMap(map)
{

}

int Items::getCountSpace(){
    int countSpace = 0;
    for (int i = 0; i < MAP_SIZE; i++){
	    for (int j = 0; j < MAP_SIZE; j++){
		    if (thisMap->getMap(i,j) == '0')
			    countSpace++;
	    }
    }
    return countSpace;
}
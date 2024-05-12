/*
Gate 클래스 : Snake Game의 Gate를 나타내는 클래스
makeGate() line 별 설명
 15		: Wall의 개수를 countWall에 저장 
 17~19	: 0 ~ countWall 중 난수 발생
 21~27	: gate1, gate2에 서로 다른 난수 저장 
 29~30	: 난수 위치에 Gate를 생성
setGate() : 난수 위치에 Gate인 '7'을 저장하는 함수
getCountWall : 현재 Map->mapArray[][]의 '1'의 개수를 반환하는 함수
deleteGate() : 현재 Map->mapArray[][]의 '7'을 '1'로 변경하는 함수
*/

class Gate
{
public:
	Gate(char mapArray[23][23]);
	void makeGate(char mapArray[23][23]);
	void setGate(char mapArray[23][23], int gate);
	int getCountWall(char mapArray[23][23]);
	void deleteGate(char mapArray[23][23]);
private:
	int countWall = 0;
	int gate1 = 0;
	int gate2 = 0;
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };
};


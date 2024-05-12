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


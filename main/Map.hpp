#define MAP_SIZE 23

using namespace std;

class Map
{
public:
	Map(int height, int width);
	void init();
	void addCh(int y, int x, char ch);
	void clear();
	void refresh();
	void setMapFirst();
	void refreshMap();
private:
	WINDOW* mapWin;
	char mapArray[MAP_SIZE][MAP_SIZE];
};

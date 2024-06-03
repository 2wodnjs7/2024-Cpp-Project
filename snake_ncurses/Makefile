CC = g++
CFLAGS = -std=c++14 -fshort-wchar

LDFLAGS =
LDLIBS = -lncurses

OBJS = Fruit.o GameProcess.o GameTimer.o Gate.o Item.o Main.o Map.o Mission.o Point.o Poison.o Score.o Snake.o Window.o 

TARGET = SnakeGameExe

all : $(TARGET)

$(TARGET) : $(OBJS) 
	$(CC) -o $@ $^ $(LDLIBS) $(CFLAGS)

Fruit.o : Fruit.cpp Fruit.hpp Item.hpp
	$(CC) -c Fruit.cpp $(LDLIBS)

GameProcess.o : GameProcess.cpp GameProcess.hpp Map.hpp Snake.hpp Fruit.hpp Poison.hpp Gate.hpp GameTimer.hpp Score.hpp Mission.hpp
	$(CC) -c GameProcess.cpp

GameTimer.o : GameTimer.cpp GameTimer.hpp Window.hpp
	$(CC) -c GameTimer.cpp 
	
Gate.o : Gate.cpp Gate.hpp Point.hpp Map.hpp
	$(CC) -c Gate.cpp

Item.o : Item.cpp Item.hpp Map.hpp
	$(CC) -c Item.cpp

Main.o : Main.cpp GameProcess.hpp
	$(CC) -c Main.cpp

Map.o : Map.cpp Map.hpp Window.hpp Point.hpp
	$(CC) -c Map.cpp

Mission.o : Mission.cpp Mission.hpp Window.hpp
	$(CC) -c Mission.cpp

Point.o : Point.cpp Point.hpp 
	$(CC) -c Point.cpp

Poison.o : Poison.cpp Poison.hpp Item.hpp
	$(CC) -c Poison.cpp

Score.o : Score.cpp Score.hpp Window.hpp
	$(CC) -c Score.cpp

Snake.o : Snake.cpp Snake.hpp Point.hpp Map.hpp
	$(CC) -c Snake.cpp

Window.o : Window.cpp Window.hpp 
	$(CC) -c Window.cpp

run :
	./$(TARGET)
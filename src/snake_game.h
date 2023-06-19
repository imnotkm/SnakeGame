#include <iostream>
#include <vector>
#include "coordinate.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const char UP = 'u';
const char DOWN = 'd';
const char LEFT = 'l';
const char RIGHT = 'r';

class Snake
{
private:
	const int row, col;
	int** gameMap;

	vector<coordinate> snake_vec;
	coordinate direction;

	int level;
	int len;
	int speed;
	bool end;
	string causeOfDeath;

public:
	const int maxLen = 6;

	vector<coordinate> walls;
	vector<coordinate> gates;
	vector<coordinate> growth_vec;
	vector<coordinate> poison_vec;
	
	int enteredGate = 0;
	int numGrew = 0;
	int numPoisoned = 0;


	Snake(int r, int c);
	~Snake();
	void init();

	int** initGameMap();
	int** updateGameMap();

	void setDirection(char d);
	char getDirection();

	coordinate getHead();
	void moveSnakeHead();
	void moveSnakeBody();

	void setGate();
	void removeGate();
	void enterGate(coordinate gate);

	void growSnake();
	void poisonSnake();

	void createGrowth();
	void removeGrowth();
	void createPoison();
	void removePoison();

	void setCause(string s);
	string getCause();
	void setEnd(bool e);
	bool getEnd();

	void setLevel();
	int getLevel();

	int getLen();
	void setSize(int new_size);
	int getSize();

	int getSpeed();
	int getRow();
	int getCol();
};
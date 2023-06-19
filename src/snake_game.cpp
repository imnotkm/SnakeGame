#include "snake_game.h"
using namespace std;
extern int map[5][21][21];

Snake::Snake(int r, int c) : row(r), col(c)
{
	gameMap = nullptr;
	level = 1;
	len = 3;
	speed = 250000;
	end = false;
}
Snake::~Snake(){delete[] gameMap;}
void Snake::init()
{
	gameMap = nullptr;

	snake_vec.clear();
	setDirection(UP);

	level++;
	len = 3;
	speed -= 25000;
	end = false;
	causeOfDeath.clear();

	walls.clear();
	gates.clear();
	growth_vec.clear();
	poison_vec.clear();

	enteredGate = 0;
	numGrew = 0;
	numPoisoned = 0;
}


void Snake::setDirection(char d)
{
	// 방향을 입력 받아 direction에 방향 벡터를 설정.
	switch(d)
	{
		case UP : direction = coordinate(-1, 0); break;
		case DOWN : direction = coordinate(1, 0); break;
		case LEFT : direction = coordinate(0, -1); break;
		case RIGHT : direction = coordinate(0, 1); break;
	}
}
char Snake::getDirection()
{
	if(direction.getY() == -1) return UP; 
	else if(direction.getY() == 1) return DOWN; 
	else if(direction.getX() == -1) return LEFT; 
	else return RIGHT;
}


int** Snake::initGameMap()
{
	// 새로운 level에 진입할 때, gameMap 초기화
	delete[] gameMap;
	gameMap = new int*[row];
	for(int i = 0; i < row; i++)
		gameMap[i] = new int[col];

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			gameMap[i][j] = map[level - 1][i][j];
			// map 상의 일반 벽의 좌표를 wall vector에 삽입, gate는 일반 벽이 위치한 곳에 생성.
			if(map[level - 1][i][j] == 1)
				walls.push_back(coordinate(i, j));
		}
	}
	// snake vector에 head 하나, body 두 개를 삽입. snake의 초기 위치는 map의 좌측 하단.
	for(int i = 0; i < 3; i++)
		snake_vec.push_back(coordinate(row - 4 + i, 1));
	// snake의 시작 방향은 위쪽.
	setDirection(UP);

	return gameMap;
}
int** Snake::updateGameMap()
{
	gameMap[snake_vec[0].getY()][snake_vec[0].getX()] = 3;
	for(int i = 1; i < snake_vec.size(); i++)
		gameMap[snake_vec[i].getY()][snake_vec[i].getX()] = 4;
	
	return gameMap;
}


void Snake::setGate()
{
	srand(time(NULL));
	int rand1 = 0;
	int rand2 = 0;
	while(rand1 == rand2)
	{
		rand1 = rand() % walls.size();
		rand2 = rand() % walls.size();
	}

	gates.push_back(walls[rand1]);
	gates.push_back(walls[rand2]);
	gameMap[gates[0].getY()][gates[0].getX()] = 7;
	gameMap[gates[1].getY()][gates[1].getX()] = 7;
}
void Snake::removeGate()
{
	if(gates.empty())
		return;
	for(int i = 0; i < 2; i++)
	{
		coordinate gate = gates.back();
		gameMap[gate.getY()][gate.getX()] = 1;
		gates.pop_back();
	}
}
void Snake::enterGate(coordinate gate)
{
	// 생성된 게이트를 통과하는 방향을 설정
	coordinate directions[4] = {coordinate(-1, 0), coordinate(1, 0), coordinate(0, -1), coordinate(0, 1)};
	coordinate tmp;

	if(gate.getY() == 20)
		direction = directions[0];
	else if(gate.getY() == 0)
		direction = directions[1];
	else if(gate.getX() == 20)
		direction = directions[2];
	else if(gate.getX() == 0)
		direction = directions[3];
	else
	{
		tmp = gate + direction;
		if(map[level - 1][tmp.getY()][tmp.getX()] == 0) {}
		else
		{
			for(int i = 0; i < 4; i++)
			{
				tmp = gate + directions[i];
				if(map[level - 1][tmp.getY()][tmp.getX()] == 0)
				{
					direction = directions[i];
					break;
				}
			}
		}
	}
	// 게이트를 통과한 뒤의 머리 좌표를 설정
	tmp = gate + direction;
	snake_vec[0].setY(tmp.getY());
	snake_vec[0].setX(tmp.getX());
	enteredGate++;
}


coordinate Snake::getHead()
{
	coordinate head(snake_vec[0].getY(), snake_vec[0].getX());
	return head;
}
void Snake::moveSnakeHead()
{
	// 뱀의 머리를 direction에 저장되어있는 방향벡터 만큼 이동.
	coordinate head = snake_vec[0];
	gameMap[head.getY()][head.getX()] = 0;
	head += direction; 
	int y = head.getY();
	int x = head.getX();

	switch(gameMap[y][x])
	{
		case 0:
			break;
		case 1:
			setEnd(true);
			causeOfDeath = "CRASHED WALL";
			break;
		case 5:
			growSnake();
			removeGrowth();
			createGrowth();
			break;
		case 6:
			poisonSnake();
			removePoison();
			createPoison();
			break;
		case 7:
			for(int i = 0; i < 2; i++)
				if(head != gates[i])
				{
					enterGate(gates[i]);
					break;
				}
			break;
	}
	moveSnakeBody();
	snake_vec[0] += direction;
}
void Snake::moveSnakeBody()
{
	// snake_vec의 마지막 원소(뱀의 꼬리)부터 앞에 연결된 부위의 좌표로 이동.
	for(int i = snake_vec.size() - 1; i > 0; i--)
	{
		coordinate body = snake_vec[i];
		gameMap[body.getY()][body.getX()] = 0;
		snake_vec[i] = snake_vec[i - 1];
	}
}


void Snake::growSnake()
{
	vector<coordinate>::const_iterator it = snake_vec.begin()++;
	snake_vec.insert(it, snake_vec[0]);
	len++;
	numGrew++;
}
void Snake::poisonSnake()
{
	coordinate tail = snake_vec.back();
	gameMap[tail.getY()][tail.getX()] = 0;
	snake_vec.pop_back();
	len--;
	numPoisoned++;
}


void Snake::createGrowth()
{
	srand(time(NULL));
	while(true)
	{
		int x = rand() % 19 + 1;
		int y = rand() % 19 + 1;
		if(gameMap[y][x] == 0)
		{
			growth_vec.push_back(coordinate(y, x));
			gameMap[y][x] = 5;
			break;
		}
	}
}
void Snake::removeGrowth()
{
	if(growth_vec.empty())
		return;
	coordinate growth = growth_vec.back();
	gameMap[growth.getY()][growth.getX()] = 0;
	growth_vec.pop_back();
}
void Snake::createPoison()
{
	srand(time(NULL));
	while(true)
	{
		int x = rand() % 19 + 1;
		int y = rand() % 19 + 1;
		if(gameMap[y][x] == 0)
		{
			poison_vec.push_back(coordinate(y, x));
			gameMap[y][x] = 6;
			break;
		}
	}
}
void Snake::removePoison()
{
	if(poison_vec.empty())
		return;
	coordinate poison = poison_vec.back();
	gameMap[poison.getY()][poison.getX()] = 0;
	poison_vec.pop_back();
}


void Snake::setCause(string s) {causeOfDeath = s;}
string Snake::getCause() {return causeOfDeath;}
void Snake::setEnd(bool e) {end = e;}
bool Snake::getEnd() {return end;}

void Snake::setLevel() {level++;}
int Snake::getLevel() {return level;}

int Snake::getLen() {return len;}
void Snake::setSize(int new_size) {snake_vec.resize(new_size);}
int Snake::getSize(){return snake_vec.size();}

int Snake::getSpeed() {return speed;}
int Snake::getRow() {return row;}
int Snake::getCol() {return col;}

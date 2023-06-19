#include "snake_game.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <ncurses.h>
#include <string>
#include <unistd.h>	//usleep(microseconds);
using namespace std;

extern int map[5][21][21];
extern int map[5][21][21];

char mission_B = 'X'; 
char mission_growth = 'X';
char mission_poison = 'X';
char mission_gate = 'X';

int goal_B = 4; 
int goal_Growth = 1;
int goal_Poison = 1;
int goal_Gate = 1;


void newWindow(float y, float x)
{ 
    clear();
    initscr();
    noecho();
    getmaxyx(stdscr, y, x);
}
int UserInput()
{ 
    int UserInput = getch();
    refresh();
    endwin();
    clear();
    return UserInput;
}
int startGame(float y, float x)
{
    newWindow(y, x);
    printw("PRESS Y TO START\n\nPRESS F5 TO REFRESH\n\nPRESS Q TO QUIT");
    return UserInput();
}
string causeOfDeath;
int finishWindow(float y, float x)
{ 
    newWindow(y, x);
    printw(causeOfDeath.data());
    printw("\n\nGAME OVER\n\nPRESS ANY KEY TO END");
    return UserInput();
}


void drawGameMap(WINDOW* gameWindow, int** gameMap) //맵 그리기
{
	werase(gameWindow);

	for(int i = 0; i < 21; i++)
	{
		for(int j = 0; j < 21; j++)
		{
			char ch;
			switch(gameMap[i][j])
			{
				case 0: 
                    ch = ' ';
                    break;
                case 1:
                    ch = '#';
                    break;
                case 2:
                    ch = 'H';
                    break;
                case 3:
                    ch = '@';
                    break;
				case 4:
					ch = 'O';
					break;
				case 5:
					ch = '+';
					break;
				case 6: 
					ch = '-';
					break;
				case 7: 
					ch = 'G';
					break;
			}
			mvwaddch(gameWindow, i, j, ch);
		}
	}
	wrefresh(gameWindow);
}
void printScoreBoard(WINDOW* w, Snake& snake)
{
	werase(w);
	wbkgd(w, COLOR_PAIR(snake.getLevel()));
	wborder(w, '|','|','-','-','.','.','.','.');
	mvwprintw(w, 1, 1, "Score Board");
  	mvwprintw(w, 2, 1, "B(Length)/(Max Length): %d/%d", snake.getLen(), snake.maxLen);
  	mvwprintw(w, 3, 1, "G(Entered Gates): %d ", snake.enteredGate);
  	mvwprintw(w, 4, 1, "+(Growth Items):  %d ", snake.numGrew);
  	mvwprintw(w, 5, 1, "-(Poison Items):  %d ", snake.numPoisoned);
  	mvwprintw(w, 6, 1, "Stage\t%d ", snake.getLevel());
	wrefresh(w);
}
void printMissionBoard(WINDOW* w, int level)
{
	werase(w);
	wbkgd(w, COLOR_PAIR(level));
	wborder(w, '|','|','-','-','.','.','.','.');
	mvwprintw(w, 1, 1, "Mission");
	mvwprintw(w, 2, 1, "B: %d\t( %c )", goal_B, mission_B);
	mvwprintw(w, 3, 1, "G: %d\t( %c )", goal_Gate, mission_gate);
	mvwprintw(w, 4, 1, "+: %d\t( %c )", goal_Growth, mission_growth);
	mvwprintw(w, 5, 1, "-: %d\t( %c )", goal_Poison, mission_poison);
	wrefresh(w);
}


void missionAccomplished(Snake& snake)
{
	if(snake.getSize() == goal_B) {mission_B ='O';}
	if(snake.numGrew == goal_Growth) {mission_growth = 'O';}
	if(snake.numPoisoned == goal_Poison) {mission_poison = 'O';}
	if(snake.enteredGate == goal_Gate) {mission_gate = 'O';}
}


int noticeChangeLevel(float y, float x, int level)
{ 
	clear();
	initscr();
	noecho();

	getmaxyx(stdscr, y, x);
	newWindow(y, x);
	printw("STAGE %d CLEAR", level - 1);
	printw("\n\nPRESS ENTER TO CONTINUE");

	return UserInput();
}
bool nextLevel(Snake& snake)
{
	if((mission_B == 'O') && (mission_gate == 'O') && (mission_growth == 'O') && (mission_poison == 'O'))
	{
		snake.init();
		if(snake.getLevel() == 6)
		{
			snake.setEnd(true);
			snake.setCause("ALL CLEAR");
		
			return false;
		}
		snake.initGameMap();
		
		mission_B = 'X'; 
		mission_growth = 'X';
		mission_poison = 'X';
		mission_gate = 'X';
		if(noticeChangeLevel(0, 0, snake.getLevel()) == KEY_ENTER) {};
		
		return true;
	}
	return false;
}


void game()
{
	float x, y;
	initscr();
	noecho();
	cbreak();

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_CYAN);
	init_pair(2, COLOR_WHITE, COLOR_GREEN);
	init_pair(3, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(4, COLOR_BLACK, COLOR_YELLOW);
	init_pair(5, COLOR_BLACK, COLOR_BLUE);

	getmaxyx(stdscr, y, x);
	WINDOW *gameWindow = newwin(21, 21, 0, 0);
  	WINDOW *scoreBoard = newwin(11, 40, 0, 21);
  	WINDOW *missionBoard = newwin(10, 40, 11, 21);

	Snake snake(21, 21);
	snake.initGameMap();
	int growthCnt = 0;
	int poisonCnt = 0;
	int gateCnt = 0;

	while(!snake.getEnd())
	{
		printScoreBoard(scoreBoard, snake);
		printMissionBoard(missionBoard, snake.getLevel());

		srand(time(NULL));
		wbkgd(gameWindow, COLOR_PAIR(snake.getLevel()));
		wattron(gameWindow, COLOR_PAIR(snake.getLevel()));
		nodelay(gameWindow, TRUE);
		keypad(gameWindow, TRUE);
		refresh();
		
		wrefresh(gameWindow);
		missionAccomplished(snake);
		drawGameMap(gameWindow, snake.updateGameMap());

		if(gateCnt == 0)
		{
			snake.setGate();
		}
		gateCnt += 1;
		if(gateCnt == 50)
		{
			snake.removeGate();
			snake.setGate();
			gateCnt = 1;
		}
		if(growthCnt == 0)
		{
			snake.createGrowth();
		}
		growthCnt += 1;
		if(growthCnt == 50)
		{ 
			snake.removeGrowth();
			snake.createGrowth();
			growthCnt = 1;
		}
		if(poisonCnt == 0)
		{
			snake.createPoison();
		}
		poisonCnt += 1;
		if (poisonCnt == 50)
		{ 
			snake.removePoison();
			snake.createPoison();
			poisonCnt = 1;
		}

		int input = wgetch(gameWindow); 
		char direction = snake.getDirection(); 
		switch(input)
		{
			case KEY_UP:
				if (direction == DOWN)
				{
					snake.setEnd(true); 
					snake.setCause("SNAKE CANNOT MOVE BACKWARDS");
				}
				else
					snake.setDirection(UP);
				break;
			case KEY_DOWN: 
				if (direction == UP)
				{
					snake.setEnd(true);
					snake.setCause("SNAKE CANNOT MOVE BACKWARDS");
				}
				else
					snake.setDirection(DOWN);
				break;
			case KEY_LEFT: 
				if (direction == RIGHT)
				{
					snake.setEnd(true);
					snake.setCause("SNAKE CANNOT MOVE BACKWARDS");
				}
				else
					snake.setDirection(LEFT);
				break;
			case KEY_RIGHT: 
				if (direction == LEFT)
				{
					snake.setEnd(true);
					snake.setCause("SNAKE CANNOT MOVE BACKWARDS");
				}
				else
					snake.setDirection(RIGHT);
				break;
			case KEY_F(5) :
				snake.setEnd(true);
				game();
			case 'q':
			case 'Q':
				snake.setEnd(true);
				snake.setCause("QUIT KEY PRESSED, SHUTTING DOWN");
				break;
		}
		if(snake.getSize() < 3)
		{
			snake.setEnd(true);
			snake.setCause("SNAKE DEAD OF POSION");
		}

		snake.moveSnakeHead(); 
		if(nextLevel(snake))
		{
			gateCnt = 0;
			growthCnt = 0;
			poisonCnt = 0;
		}
		usleep(snake.getSpeed());
		causeOfDeath = snake.getCause();
	}
}


int main()
{
	if (startGame(0, 0) == 'y') game();
  	finishWindow(0, 0);
	endwin();
	return 0;
}

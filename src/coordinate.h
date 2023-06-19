#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <string>

using namespace std;

class coordinate{
private:
	int x,y;
public:
	coordinate();
	coordinate(int x, int y);

	void setX(int x);
	void setY(int y);
	int getX() const;
	int getY() const;

    coordinate& getRandom();

	coordinate& operator=(const coordinate& v);
	coordinate& operator+=(const coordinate& v);
	coordinate operator+(const coordinate& v);
	coordinate& operator-=(const coordinate& v);
	coordinate operator-(const coordinate& v);
	bool operator==(const coordinate& v);
	bool operator!=(const coordinate& v);
};

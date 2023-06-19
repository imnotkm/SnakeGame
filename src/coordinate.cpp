#include "coordinate.h"
using namespace std;

coordinate::coordinate() : y(0), x(0) {}
coordinate::coordinate(int y, int x): y(y), x(x) {}

void coordinate::setY(int y){this->y = y;}
void coordinate::setX(int x){this->x = x;}
int coordinate::getY() const {return this->y;}
int coordinate::getX() const {return this->x;}

coordinate& coordinate::getRandom()
{
	srand(time(NULL));
    this->y = rand() % 19 + 1;
    this->x = rand() % 19 + 1;
    return *this;
}

coordinate& coordinate::operator=(const coordinate& v)
{
	setY(v.getY());
	setX(v.getX());
	return *this;
}
coordinate& coordinate::operator+=(const coordinate& v)
{
	setY(getY() + v.getY());
	setX(getX() + v.getX());
	return *this;
}
coordinate coordinate::operator+(const coordinate& v)
{
	coordinate tmp(getY(), getX());
	tmp += v;
	return tmp;
}
coordinate& coordinate::operator-=(const coordinate& v)
{
	setY(getY() - v.getY());
	setX(getX() - v.getX());
	return *this;
}
coordinate coordinate::operator-(const coordinate& v)
{
	coordinate tmp(getY(), getX());
	tmp -= v;
	return tmp;
}
bool coordinate::operator==(const coordinate& v)
{
	return getY() == v.getY() && getX() == v.getX();
}
bool coordinate::operator!=(const coordinate& v)
{
	return !(*this == v);
}

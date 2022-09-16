#include "Point.h"
#include <math.h>

Point::Point(int x, int y)
{
	this->x = x, this->y = y;
}

Point::Point()
{
}

double Point::length(Point other)
{
	return pow(pow(other.x - this->x, 2) + pow(other.y - this->y, 2), 0.5);
}

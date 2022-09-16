#include "circle.h"
#define PI 3.1415926535;

Circle::Circle()
{
}

Circle::Circle(Point p, int radius)
{
	this->p = p;
	this->radius = radius;
}

double Circle::Area() { return radius * radius * PI; }

double Circle::Perimeter() { return 2 * radius * PI; }

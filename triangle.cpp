#include "Triangle.h"

Triangle::Triangle(Point p1, Point p2, Point p3)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

Triangle::Triangle()
{
}


double Triangle::Area()
{
	double res = (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2;

	if (res < 0)
		res *= -1;

	return res;
}

double Triangle::Perimeter()
{
	return p1.length(p2) + p1.length(p3) + p2.length(p3);
}

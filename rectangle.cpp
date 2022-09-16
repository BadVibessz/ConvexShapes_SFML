#include "rectangle.h"

Rectangle::Rectangle(Point p1, Point p2)
{
	this->p1 = p1;
	this->p2 = Point(p2.x, p1.y);
	this->p3 = p2;
	this->p4 = Point(p1.x, p2.y);
}

Rectangle::Rectangle()
{
}

double Rectangle::Area()
{
	double height = p1.length(p2);
	double width = p1.length(p4);

	return height * width;
}

double Rectangle::Perimeter()
{
	return 2 * (p1.length(p2) + p1.length(p4));
}


#pragma once
#include "figure.h"
#include "Point.h"

class Rectangle : Figure
{
public:
	Point p1, p2, p3, p4;

	Rectangle(Point p1, Point p2);
	Rectangle();

	double  Area() override;
	double Perimeter() override;


};


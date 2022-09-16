#pragma once
#include "figure.h"
#include "Point.h"

class Triangle : public Figure
{
public:
	Point p1, p2, p3;
	Triangle(Point p1, Point p2, Point p3);
	Triangle();

	double Area() override;
	double Perimeter() override;
};




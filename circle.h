#pragma once
#include <SFML/Graphics/CircleShape.hpp>

#include "figure.h"
#include "Point.h"

class Circle : Figure
{
public:
	Point p;
	int radius;

	Circle();
	Circle(Point p, int radius);

	double Area() override;
	double Perimeter() override;
};


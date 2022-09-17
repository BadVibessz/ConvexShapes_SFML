#pragma once
#include <SFML/Graphics/CircleShape.hpp>

#include "figure.h"
#include "Point.h"

class CircleDecorator : public Figure
{
public:
	CircleDecorator(CircleShape* circle_shape);

	double Area() override;
	double Perimeter() override;

	void SetRadius(float rad);
};


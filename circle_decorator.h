#pragma once
#include <SFML/Graphics/CircleShape.hpp>

#include "figure.h"
#include "Point.h"

class CircleDecorator : public Figure
{
public:
	CircleDecorator(CircleShape* circle_shape);
	CircleDecorator(CircleDecorator* circleDecorator);

	double Area() override;
	double Perimeter() override;
	std::string GetType() override;

	void SetRadius(float rad);
};


#pragma once
#include "figure.h"
#include "Point.h"

class TriangleDecorator : public Figure
{
public:
	TriangleDecorator(ConvexShape* triangle_shape);

	double Area() override;
	double Perimeter() override;

	void SetPointCount(int count);
	void SetPoint(int i, Vector2f point);
};




#pragma once
#include "figure.h"
#include "Point.h"

class TriangleDecorator : public Figure
{
public:
	TriangleDecorator();
	TriangleDecorator(ConvexShape* triangle_shape);
	TriangleDecorator(TriangleDecorator* decorator);

	double Area() override;
	double Perimeter() override;
	std::string GetType() override;

	void SetPointCount(int count);
	void SetPoint(int i, Vector2f point);
	Vector2f GetPoint(int i);
};




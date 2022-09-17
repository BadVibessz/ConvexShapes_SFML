#pragma once
#include "figure.h"
#include "Point.h"

class RectangleDecorator :  public Figure
{
public:
	RectangleDecorator(RectangleShape* rectangle_shape);

	double  Area() override;
	double Perimeter() override;
	
	void SetSize(Vector2f vec);

};


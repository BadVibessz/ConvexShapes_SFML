#pragma once
#include "rectangle_shape_decorator.h"

class HighlightDecorator : public RectangleShapeDecorator
{
public:
	HighlightDecorator(RectangleShape* rectangle) : RectangleShapeDecorator(rectangle) {}

	void Highlight(float thickness, Color color);

};


#pragma once
#include "figure_builder.h"
#include "rectangle_decorator.h"

class RectangleBuilder : public FigureBuilder
{
private:
	RectangleDecorator* _rectangleDecorator = new RectangleDecorator();

public:
	RectangleBuilder();
	FigureBuilder* Build() override;
	RectangleBuilder* SetSize(Vector2f size);
};


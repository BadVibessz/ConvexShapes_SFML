#pragma once
#include "figure_factory.h"
#include "figure.h"
#include "rectangle_decorator.h"
class RectangleFactory : public FigureFactory
{
private:
	RectangleDecorator* _rectangle_decorator;

public:
	RectangleFactory(Vector2f position, Vector2f size, Color color,Color outlineColor, float outlineThickness);
	Figure* GetFigure() override;
};


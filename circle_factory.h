#pragma once
#include "figure_factory.h"
#include "figure.h"
#include "circle_decorator.h"
#include <string>

class CircleFactory : public FigureFactory
{
private:
	CircleDecorator* _circle_decorator;

public:
	CircleFactory(Vector2f origin, int radius, Color fillColor, Color outlineColor, float outlineThickness);
	Figure* GetFigure() override;

};


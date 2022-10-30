#pragma once
#include "figure_factory.h"
#include "figure.h"
#include "triangle_decorator.h"

class TriangleFactory : public FigureFactory
{
private:
	TriangleDecorator* _triangle_decorator;

public:
	TriangleFactory(Vector2f p1, Vector2f p2, Vector2f p3, Color color, Color outlineColor, float outlineThickness);
	Figure* GetFigure() override;
};


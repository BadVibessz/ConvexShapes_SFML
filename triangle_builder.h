#pragma once
#include "figure_builder.h"
#include "triangle_decorator.h"

class TriangleBuilder : public FigureBuilder
{

private:
	TriangleDecorator* _triangleDecorator = new TriangleDecorator();

public:
	FigureBuilder* Build() override;

	TriangleBuilder();
	TriangleBuilder* SetPoint(int ind, Vector2f point);
	TriangleBuilder* SetPointCount(int count);
	

};


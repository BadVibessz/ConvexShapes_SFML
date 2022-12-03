#pragma once
#include "figure.h"

class FigureBuilder
{
protected:
	Figure* _figure;

public:
	virtual FigureBuilder* Build() = 0;

	virtual FigureBuilder* SetPosition(Vector2f position);
	virtual FigureBuilder* SetFillColor(Color color);
	virtual FigureBuilder* SetOutlineColor(Color color);
	virtual FigureBuilder* SetOutlineThickness(float thickness);

	Figure* GetFigure();

};


#pragma once
#include "figure.h"

class FigureFactory
{
public:
	virtual Figure* GetFigure() = 0;
};


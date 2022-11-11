#pragma once
#include "figure.h"


class Visitor
{
public:
	virtual void VisitFigure(Figure* figure) = 0;
};
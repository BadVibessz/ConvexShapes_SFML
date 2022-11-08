#pragma once
#include "visitor.h"

using namespace std;
using namespace sf;

class FillVisitor : public Visitor
{
private:
	Color _color;


public:
	FillVisitor(Color color);
	void VisitFigure(Figure* figure) override;

};


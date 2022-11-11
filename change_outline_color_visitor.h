#pragma once
#include "visitor.h"

using namespace std;
using namespace sf;

class ChangeOutlineColorVisitor : public Visitor
{

private:
	Color _color;

public:
	ChangeOutlineColorVisitor(Color color);
	void VisitFigure(Figure* figure) override;
};


#include "fill_visitor.h"

FillVisitor::FillVisitor(Color color)
{
	this->_color = color;
}

void FillVisitor::VisitFigure(Figure* figure)
{
	figure->SetFillColor(_color);
}

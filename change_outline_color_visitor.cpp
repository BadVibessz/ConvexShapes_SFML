#include "change_outline_color_visitor.h"

ChangeOutlineColorVisitor::ChangeOutlineColorVisitor(Color color)
{
	this->_color = color;
}

void ChangeOutlineColorVisitor::VisitFigure(Figure* figure)
{
	figure->SetOutlineColor(_color);
}

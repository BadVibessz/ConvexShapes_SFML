#include "change_outline_width_visitor.h"

ChangeOutlineWidthVisitor::ChangeOutlineWidthVisitor(float thickness)
{
	this->_thickness = thickness;
}

void ChangeOutlineWidthVisitor::VisitFigure(Figure* figure)
{
	figure->SetOutlineThickness(_thickness);
}

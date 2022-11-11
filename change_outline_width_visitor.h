#pragma once
#include "visitor.h"

class ChangeOutlineWidthVisitor : public Visitor
{

private:
	float _thickness;

public:
	ChangeOutlineWidthVisitor(float thickness);
	void VisitFigure(Figure* figure) override;
};


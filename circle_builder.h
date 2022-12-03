#pragma once
#include "figure_builder.h"
#include "circle_decorator.h"

class CircleBuilder : public FigureBuilder
{

private:
	CircleDecorator* _circleDecorator = new CircleDecorator();
public:
	CircleBuilder();
	FigureBuilder* Build() override;
	CircleBuilder* SetRadius(float radius);


};


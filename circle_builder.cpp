#include "circle_builder.h"

CircleBuilder::CircleBuilder()
{
	this->_figure = _circleDecorator;
}

FigureBuilder* CircleBuilder::Build()
{
	return this;
}

CircleBuilder* CircleBuilder::SetRadius(float radius)
{
	this->_circleDecorator->SetRadius(radius);
	return this;
}

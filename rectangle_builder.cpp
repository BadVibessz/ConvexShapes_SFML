#include "rectangle_builder.h"

RectangleBuilder::RectangleBuilder()
{
	this->_figure = _rectangleDecorator;
}

FigureBuilder* RectangleBuilder::Build()
{
	return this;
}

RectangleBuilder* RectangleBuilder::SetSize(Vector2f size)
{
	this->_rectangleDecorator->SetSize(size);
	return this;
}

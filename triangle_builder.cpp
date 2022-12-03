#include "triangle_builder.h"



FigureBuilder* TriangleBuilder::Build()
{
	return this;
}

TriangleBuilder::TriangleBuilder()
{
	this->_figure = _triangleDecorator;
}

TriangleBuilder* TriangleBuilder::SetPoint(int ind, Vector2f point)
{
	this->_triangleDecorator->SetPoint(ind, point);
	return this;
}

TriangleBuilder* TriangleBuilder::SetPointCount(int count)
{
	this->_triangleDecorator->SetPointCount(count);
	return this;
}

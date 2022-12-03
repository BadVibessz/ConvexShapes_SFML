#include "figure_builder.h"

FigureBuilder* FigureBuilder::SetPosition(Vector2f position)
{
	this->_figure->SetPosition(position);
	return this;
}

FigureBuilder* FigureBuilder::SetFillColor(Color color)
{
	this->_figure->SetFillColor(color);
	return this;

}

FigureBuilder* FigureBuilder::SetOutlineColor(Color color)
{
	this->_figure->SetOutlineColor(color);
	return this;

}

FigureBuilder* FigureBuilder::SetOutlineThickness(float thickness)
{
	this->_figure->SetOutlineThickness(thickness);
	return this;

}

Figure* FigureBuilder::GetFigure()
{
	return this->_figure;
}

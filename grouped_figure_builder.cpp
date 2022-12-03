#include "grouped_figure_builder.h"

GroupedFigureBuilder::GroupedFigureBuilder()
{
	this->_figure = _groupedFigure;
}

FigureBuilder* GroupedFigureBuilder::Build()
{
	return this;
}

FigureBuilder* GroupedFigureBuilder::SetPosition(Vector2f position)
{
	this->_groupedFigure->SetPosition(position);
	return this;
}

GroupedFigureBuilder* GroupedFigureBuilder::AddFigure(Figure* figure)
{
	this->_groupedFigure->AddFigure(figure);
	return this;
}


FigureBuilder* GroupedFigureBuilder::SetFillColor(Color color)
{
	this->_groupedFigure->SetFillColor(color);
	return this;
}


FigureBuilder* GroupedFigureBuilder::SetOutlineColor(Color color)
{
	this->_groupedFigure->SetOutlineColor(color);
	return this;
}


FigureBuilder* GroupedFigureBuilder::SetOutlineThickness(float thickness)
{
	this->_groupedFigure->SetOutlineThickness(thickness);
	return this;
}

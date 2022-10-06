#include "grouped_figure.h"

double GroupedFigure::Area()
{
	double result = 0.0;

	for (auto figure : _figures)
		result += figure->Area();

	return result;
}

double GroupedFigure::Perimeter()
{
	double result = 0.0;

	for (auto figure : _figures)
		result += figure->Perimeter();

	return result;
}

std::string GroupedFigure::GetType()
{
	return "Grouped";
}

void GroupedFigure::AddFigure(Figure* figure)
{
	this->_figures.push_back(figure);
}

void GroupedFigure::DeleteFigure(Figure* figure)
{
	auto it = find(_figures.begin(), _figures.end(), figure);

	if (it != _figures.end())
		_figures.erase(it);
}

vector<Figure*> GroupedFigure::GetShapes()
{
	return _figures;
}

void GroupedFigure::Highlight()
{
	for (auto figure : _figures)
			figure->Highlight();
}

bool GroupedFigure::IsHighlighted()
{
	return _figures.front()->IsHighlighted();
}

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

vector<Figure*> GroupedFigure::GetFigures()
{
	return _figures;
}

void GroupedFigure::SetPosition(Vector2f position)
{
	auto rect = GetPosition();

	auto dx = position.x - rect.x;
	auto dy = position.y - rect.y;

	for (auto figure : _figures)
	{
		auto pos = figure->GetPosition();
		pos.x += dx;
		pos.y += dy;

		figure->SetPosition(pos);
	}



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

bool GroupedFigure::ContainsPoint(Vector2f point)
{
	for (auto figure : _figures)
		if (figure->ContainsPoint(point))
			return true;
	return false;
}

FloatRect GroupedFigure::GetGlobalBounds()
{
	auto rect = _figures[0]->GetGlobalBounds();

	Vector2<float> min;
	min.x = rect.left;
	min.y = rect.top;

	Vector2<float> max;
	max.x = rect.left + rect.width;
	max.y = rect.top + rect.height;

	for (auto figure : _figures)
	{
		auto tempRect = figure->GetGlobalBounds();

		if (rect.left < min.x)
			min.x = rect.left;

		if (rect.top < min.y)
			min.y = rect.top;

		if ((rect.left + rect.width) > max.x)
			max.x = rect.left + rect.width;
		if ((rect.top + rect.height) > max.y)
			max.y = rect.top + rect.height;

	}
	return FloatRect(min.x, min.y, abs(min.x - max.x), abs(min.y - max.y));
}

Vector2f GroupedFigure::GetPosition()
{

	auto rect = GetGlobalBounds();
	return { rect.left, rect.top };

}

Figure* GroupedFigure::GetFigureThatContainsPoint(Vector2f point)
{
	Figure* figure = nullptr;

	for (auto fig : _figures)
	{
		if (fig->GetType() == "Grouped")
		{
			for (auto grouped : ((GroupedFigure*)fig)->GetFigures())
			{
				if (grouped->ContainsPoint(point))
					figure = grouped;
			}
		}
		else
		{
			if (fig->ContainsPoint(point))
				return fig;
		}

	}

	while (figure->GetType() == "Grouped")
		figure = GetFigureThatContainsPoint(point);


	return figure;
}

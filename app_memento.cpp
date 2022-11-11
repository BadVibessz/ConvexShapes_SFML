#include "app_memento.h"
#include "circle_decorator.h"
#include "rectangle_decorator.h"
#include "triangle_decorator.h"

AppMemento::AppMemento(vector<Figure*> figures)
{
	this->_figures = figures;
}

vector<Figure*> AppMemento::GetFigures()
{
	auto vec = vector<Figure*>();
	for (auto figure : _figures)
	{
		if (figure->GetType() == "Circle")
		{
			auto circle = ((CircleDecorator*)figure);
			vec.push_back(new CircleDecorator(((CircleShape*)circle->GetShape())));
		}
		else if (figure->GetType() == "Rectangle")
		{
			auto rect = ((RectangleDecorator*)figure);
			vec.push_back(new RectangleDecorator(rect));
		}
		else if (figure->GetType() == "Triangle")
		{
			auto triag = ((TriangleDecorator*)figure);
			vec.push_back(new TriangleDecorator(((ConvexShape*)triag->GetShape())));
		}

	/*	auto circl = new CircleShape();
		circl->setPosition({ 100,100 });
		circl->setRadius(20);
		circl->setOutlineColor(Color::Red);
		circl->setOutlineThickness(2);

		vec.push_back(new CircleDecorator(circl));*/

	}

	return vec;
}
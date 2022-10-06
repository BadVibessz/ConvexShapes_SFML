#include "drawer.h"
#include "file_manager.h"
#include "my_extensions.h"
#include "circle_factory.h"
#include "rectangle_factory.h"
#include "triangle_factory.h"



using namespace std;

Drawer::Drawer()
{
}

Drawer::Drawer(RenderWindow* window)
{
	this->_window = window;
	this->width = window->getSize().x;
	this->height = window->getSize().y;
}

void Drawer::DrawLine(Point p1, Point p2, Color color)
{
	Vertex line[] =
	{
		Vertex(Vector2f(p1.x, p1.y),color),
		Vertex(Vector2f(p2.x, p2.y),color)
	};
	_window->draw(line, 2, Lines);
}

void Drawer::DrawAxis(Color color)
{
	DrawLine(Point(0, height / 2), Point(width, height / 2), color);
	DrawLine(Point(width / 2, 0), Point(width / 2, height), color);
}


void Drawer::DrawFigures(vector<Figure*> figures)
{
	for (auto figure : figures)
		DrawFigure(figure);
}

void Drawer::DrawFigure(Figure* figure)
{
	figure->Draw(*_window);
}


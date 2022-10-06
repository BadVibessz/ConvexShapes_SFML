#include <SFML/Graphics.hpp>

#include "circle_decorator.h"
#include "Point.h"
#include "rectangle_decorator.h"
#include "triangle_decorator.h"
#include "file_manager.h"

using namespace sf;

#pragma once
class Drawer
{
private:
	RenderWindow* _window;
	int width, height;

public:
	Drawer();
	Drawer(RenderWindow* window);

	void DrawLine(Point p1, Point p2, Color color);
	void DrawAxis(Color color);
	void DrawFigures(vector<Figure*> figures);
	void DrawFigure(Figure* figure);

};


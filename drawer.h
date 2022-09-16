#include <SFML/Graphics.hpp>

#include "circle.h"
#include "Point.h"
#include "rectangle.h"
#include "Triangle.h"
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
	Drawer(RenderWindow* window, int width, int height);

	void DrawLine(Point p1, Point p2, Color color);
	void DrawAxis(Color color);
	void DrawTriangle(Point p1, Point p2, Point p3, Color color);
	void DrawTriangle(Triangle triangle, Color color);
	void DrawRectangle(Point p1, Point p2, Color color);
	void DrawRectangle(Rectangle rectangle, Color color);
	void DrawCircle(Point origin, int radius, Color color);
	void DrawCircle(Circle circle, Color color);
	void DrawFiguresFromFIle();
};


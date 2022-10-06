#include "triangle_factory.h"

TriangleFactory::TriangleFactory(Vector2f p1, Vector2f p2, Vector2f p3, Color color)
{

	auto triangle = new TriangleDecorator(new ConvexShape());
	triangle->SetPointCount(3);
	triangle->SetPoint(0, Vector2f(p1.x, p1.y));
	triangle->SetPoint(1, Vector2f(p2.x, p2.y));
	triangle->SetPoint(2, Vector2f(p3.x, p3.y));
	triangle->SetFillColor(color);

	this->_triangle_decorator = triangle;
}

Figure* TriangleFactory::GetFigure()
{
	return this->_triangle_decorator;
}



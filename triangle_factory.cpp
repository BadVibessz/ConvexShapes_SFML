#include "triangle_factory.h"

TriangleFactory::TriangleFactory(Vector2f p1, Vector2f p2, Vector2f p3, Color color,
	Color outlineColor, float outlineThickness)
{

	auto triangle = new TriangleDecorator(new ConvexShape());
	triangle->SetPointCount(3);
	triangle->SetPoint(0, Vector2f(p1.x, p1.y));
	triangle->SetPoint(1, Vector2f(p2.x, p2.y));
	triangle->SetPoint(2, Vector2f(p3.x, p3.y));
	triangle->SetFillColor(color);
	triangle->SetOutlineColor(outlineColor);
	triangle->SetOutlineThickness(outlineThickness);

	auto shape = triangle->GetShape();

	float w = shape->getGlobalBounds().width;
	float h = shape->getGlobalBounds().height;
	shape->setOrigin(w / 2, h / 2);

	this->_triangle_decorator = triangle;
}

Figure* TriangleFactory::GetFigure()
{
	return this->_triangle_decorator;
}



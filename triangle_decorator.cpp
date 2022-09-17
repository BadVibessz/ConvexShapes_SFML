#include "triangle_decorator.h"

TriangleDecorator::TriangleDecorator(ConvexShape* triangle_shape)
{
	_shape = triangle_shape;
}

double TriangleDecorator::Area()
{
	auto p1 = ((ConvexShape*)_shape)->getPoint(0);
	auto p2 = ((ConvexShape*)_shape)->getPoint(1);
	auto p3 = ((ConvexShape*)_shape)->getPoint(2);

	double res = (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2;

	if (res < 0)
		res *= -1;

	return res;
}

double TriangleDecorator::Perimeter()
{
	auto p1 = Point(((ConvexShape*)_shape)->getPoint(0).x, ((ConvexShape*)_shape)->getPoint(0).y);
	auto p2 = Point(((ConvexShape*)_shape)->getPoint(1).x, ((ConvexShape*)_shape)->getPoint(1).y);
	auto p3 = Point(((ConvexShape*)_shape)->getPoint(2).x, ((ConvexShape*)_shape)->getPoint(2).y);

	return p1.length(p2) + p1.length(p3) + p2.length(p3);
}

void TriangleDecorator::SetPointCount(int count)
{
	((ConvexShape*)_shape)->setPointCount(count);
}

void TriangleDecorator::SetPoint(int i, Vector2f vec)
{
	((ConvexShape*)_shape)->setPoint(i, vec);
}

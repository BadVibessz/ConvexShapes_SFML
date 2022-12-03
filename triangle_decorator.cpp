#include "triangle_decorator.h"

TriangleDecorator::TriangleDecorator()
{
	this->_shape = new ConvexShape();
}

TriangleDecorator::TriangleDecorator(ConvexShape* triangle_shape)
{
	_shape = triangle_shape;
}

TriangleDecorator::TriangleDecorator(TriangleDecorator* decorator)
{

	auto newShape = new ConvexShape();
	auto oldShape = ((ConvexShape*)decorator->GetShape());


	auto col = oldShape->getFillColor();

	newShape->setPosition(oldShape->getPosition());
	newShape->setPointCount(oldShape->getPointCount());
	newShape->setPoint(0, oldShape->getPoint(0));
	newShape->setPoint(1, oldShape->getPoint(1));
	newShape->setPoint(2, oldShape->getPoint(2));
	newShape->setFillColor(oldShape->getFillColor());
	newShape->setOutlineColor(oldShape->getOutlineColor());
	newShape->setOutlineThickness(oldShape->getOutlineThickness());

	_fillColor = oldShape->getFillColor();
	_outlineColor = oldShape->getOutlineColor();
	_outlineThikness = oldShape->getOutlineThickness();



	/*float w = newShape->getGlobalBounds().width;
	float h = newShape->getGlobalBounds().height;
	newShape->setOrigin(w / 2, h / 2);*/


	this->_shape = newShape;

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

std::string TriangleDecorator::GetType()
{
	return "Triangle";
}

void TriangleDecorator::SetPointCount(int count)
{
	((ConvexShape*)_shape)->setPointCount(count);
}

void TriangleDecorator::SetPoint(int i, Vector2f vec)
{
	((ConvexShape*)_shape)->setPoint(i, vec);
}

Vector2f TriangleDecorator::GetPoint(int i)
{
	return _shape->getPoint(i);
}

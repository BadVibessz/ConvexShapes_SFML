#include "rectangle_decorator.h"


RectangleDecorator::RectangleDecorator(RectangleShape* rectangle_shape)
{
	this->_shape = rectangle_shape;
}

double RectangleDecorator::Area()
{
	auto size = ((RectangleShape*)_shape)->getSize();
	return size.x * size.y;
}

double RectangleDecorator::Perimeter()
{
	auto size = ((RectangleShape*)_shape)->getSize();
	return 2 * (size.x + size.y);
}

void RectangleDecorator::SetSize(Vector2f vec)
{
	((RectangleShape*)_shape)->setSize(vec);
}


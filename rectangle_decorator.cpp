#include "rectangle_decorator.h"


RectangleDecorator::RectangleDecorator(RectangleShape* rectangle_shape)
{
	this->_shape = rectangle_shape;


	/*float w = this->_shape->getGlobalBounds().width;
	float h = this->_shape->getGlobalBounds().height;
	this->_shape->setOrigin(w / 2, h / 2);*/

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

std::string RectangleDecorator::GetType()
{
	return "Rectangle";
}

void RectangleDecorator::SetSize(Vector2f vec)
{
	((RectangleShape*)_shape)->setSize(vec);
}


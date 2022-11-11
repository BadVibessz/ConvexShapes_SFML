#include "rectangle_decorator.h"


RectangleDecorator::RectangleDecorator(RectangleShape* rectangle_shape)
{
	this->_shape = rectangle_shape;


	/*float w = this->_shape->getGlobalBounds().width;
	float h = this->_shape->getGlobalBounds().height;
	this->_shape->setOrigin(w / 2, h / 2);*/

}

RectangleDecorator::RectangleDecorator(RectangleDecorator* rectangleDecorator)
{
	auto newShape = new RectangleShape();
	auto oldShape = ((RectangleShape*)rectangleDecorator->GetShape());

	// todo:

	auto col = oldShape->getFillColor();

	newShape->setPosition(oldShape->getPosition());
	newShape->setSize(oldShape->getSize());
	newShape->setFillColor(oldShape->getFillColor());
	newShape->setOutlineColor(oldShape->getOutlineColor());
	newShape->setOutlineThickness(oldShape->getOutlineThickness());

	float w = newShape->getGlobalBounds().width;
	float h = newShape->getGlobalBounds().height;
	newShape->setOrigin(w / 2, h / 2);


	this->_shape = newShape;

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


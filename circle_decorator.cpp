#include "circle_decorator.h"
#define PI 3.1415926535;



CircleDecorator::CircleDecorator()
{
	this->_shape = new CircleShape();
}

CircleDecorator::CircleDecorator(CircleShape* circle_shape)
{
	this->_shape = circle_shape;
}

CircleDecorator::CircleDecorator(CircleDecorator* circleDecorator)
{
	auto newShape = new CircleShape();
	auto oldShape = ((CircleShape*)circleDecorator->GetShape());

	newShape->setPosition(oldShape->getPosition());
	newShape->setRadius(oldShape->getRadius());
	newShape->setFillColor(oldShape->getFillColor());
	newShape->setOutlineColor(oldShape->getOutlineColor());
	newShape->setOutlineThickness(oldShape->getOutlineThickness());


	_fillColor = oldShape->getFillColor();
	_outlineColor = oldShape->getOutlineColor();
	_outlineThikness = oldShape->getOutlineThickness();
	//float w = newShape->getGlobalBounds().width;
	//float h = newShape->getGlobalBounds().height;

	//newShape->setOrigin(w / 2, h / 2);


	this->_shape = newShape;
}

double CircleDecorator::Area()
{
	return pow(((CircleShape*)_shape)->getRadius(), 2) * PI;
}

double CircleDecorator::Perimeter() { return 2 * ((CircleShape*)_shape)->getRadius() * PI; }

std::string CircleDecorator::GetType()
{
	return "Circle";
}

void CircleDecorator::SetRadius(float rad)
{
	((CircleShape*)_shape)->setRadius(rad);
}

float CircleDecorator::GetRadius()
{
	return ((CircleShape*)_shape)->getRadius();
}

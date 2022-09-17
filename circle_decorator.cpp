#include "circle_decorator.h"
#define PI 3.1415926535;

CircleDecorator::CircleDecorator(CircleShape* circle_shape)
{
	this->_shape = circle_shape;

}

double CircleDecorator::Area()
{
	return pow(((CircleShape*)_shape)->getRadius(), 2) * PI;
}

double CircleDecorator::Perimeter() { return 2 * ((CircleShape*)_shape)->getRadius() * PI; }

void CircleDecorator::SetRadius(float rad)
{
	((CircleShape*)_shape)->setRadius(rad);
}

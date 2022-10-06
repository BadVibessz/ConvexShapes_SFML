#include "rectangle_factory.h"

RectangleFactory::RectangleFactory(Vector2f position, Vector2f size, Color color)
{
	auto rectangle = new RectangleDecorator(new RectangleShape());
	rectangle->SetPosition(Vector2f(position.x, position.y));
	rectangle->SetSize(Vector2f(size.y, size.x));
	rectangle->SetFillColor(Color(120, 255, 0, 100));

	auto shape = rectangle->GetShape();

	float w = shape->getGlobalBounds().width;
	float h = shape->getGlobalBounds().height;
	shape->setOrigin(w / 2, h / 2);

	this->_rectangle_decorator = rectangle;
}

Figure* RectangleFactory::GetFigure()
{
	return this->_rectangle_decorator;
}


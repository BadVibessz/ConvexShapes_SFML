#include "rectangle_factory.h"

RectangleFactory::RectangleFactory(Vector2f position, Vector2f size, Color color,
	Color outlineColor, float outlineThickness)
{
	auto rectangle = new RectangleDecorator(new RectangleShape());
	rectangle->SetPosition(position);
	rectangle->SetSize(size);
	rectangle->SetFillColor(color);
	rectangle->SetOutlineColor(outlineColor);
	rectangle->SetOutlineThickness(outlineThickness);

	auto shape = rectangle->GetShape();

	/*float w = shape->getGlobalBounds().width;
	float h = shape->getGlobalBounds().height;
	shape->setOrigin(w / 2, h / 2);*/

	this->_rectangle_decorator = rectangle;
}

Figure* RectangleFactory::GetFigure()
{
	return this->_rectangle_decorator;
}


#include "figure.h"

void Figure::SetFillColor(Color color)
{
	this->_shape->setFillColor(color);
	this->_shape->setOutlineThickness(2);
	this->_shape->setOutlineColor(Color(0, 0, 0));
}

void Figure::SetPosition(Vector2f pos)
{
	this->_shape->setPosition(pos);
}

void Figure::Draw(RenderWindow& window)
{
	window.draw(*this->_shape);
}

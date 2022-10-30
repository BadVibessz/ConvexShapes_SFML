#include "figure.h"

void Figure::SetFillColor(Color color)
{
	this->_shape->setFillColor(color);
}

void Figure::SetOutlineColor(Color color)
{
	this->_shape->setOutlineColor(color);
}

void Figure::SetOutlineThickness(float thickness)
{
	this->_shape->setOutlineThickness(thickness);
}

void Figure::SetPosition(Vector2f pos)
{
	this->_shape->setPosition(pos);
	if (_rectangle != nullptr)
		this->_rectangle->setPosition(Vector2f(_shape->getGlobalBounds().left, _shape->getGlobalBounds().top));
}

void Figure::Highlight()
{
	if (_rectangle == nullptr)
	{
		auto rect = GetShape()->getGlobalBounds();
		_rectangle = new RectangleShape(Vector2f(rect.width, rect.height));
		_rectangle->setPosition(Vector2f(rect.left, rect.top));
		_rectangle->setFillColor(Color::Transparent);
		_rectangle->setOutlineThickness(2);
		_rectangle->setOutlineColor(Color::Transparent);
	}

	if (_is_highlighted) 
	{
		_is_highlighted = false;

		_rectangle->setOutlineColor(Color::Transparent);
	}
	else
	{
		_is_highlighted = true;

		_rectangle->setOutlineColor(Color::Red);
	}



}

bool Figure::IsHighlighted()
{
	return _is_highlighted;
}

Shape* Figure::GetShape()
{
	return this->_shape;
}


bool Figure::ContainsPoint(Vector2f point)
{
	return _shape->getGlobalBounds().contains(point);
}

FloatRect Figure::GetGlobalBounds()
{
	return this->_shape->getGlobalBounds();
}

Vector2f Figure::GetPosition()
{
	return this->_shape->getPosition();
}

void Figure::Draw(RenderWindow& window)
{
	window.draw(*this->_shape);
	if (this->_is_highlighted)
		window.draw(*this->_rectangle);
}

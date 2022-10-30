#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Figure
{
protected:
	Shape* _shape;
	bool _is_highlighted = false;
	bool _is_moving = false;
	RectangleShape* _rectangle = nullptr;

	Color _fillColor;

public:
	virtual double Area() = 0;
	virtual double Perimeter() = 0;
	virtual bool ContainsPoint(Vector2f point);
	virtual FloatRect GetGlobalBounds();
	virtual Vector2f GetPosition();

	virtual std::string GetType() = 0;

	void Draw(RenderWindow& window);
	virtual void SetFillColor(Color color);
	virtual void SetOutlineColor(Color color);
	virtual void SetOutlineThickness(float thickness);
	virtual void SetPosition(Vector2f position);

	virtual void Highlight();
	virtual bool IsHighlighted();

	Shape* GetShape();


};


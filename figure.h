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

public:
	virtual double Area() = 0;
	virtual double Perimeter() = 0;

	virtual std::string GetType() = 0;

	void Draw(RenderWindow& window);
	void SetFillColor(Color color);
	void SetPosition(Vector2f position);

	virtual void Highlight();
	virtual bool IsHighlighted();

	Shape* GetShape();


};


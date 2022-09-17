#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Figure
{
protected:
	Shape* _shape;

public:
	virtual double Area() = 0;
	virtual double Perimeter() = 0;

	void Draw(RenderWindow& window);
	void SetFillColor(Color color);
	void SetPosition(Vector2f position);



};


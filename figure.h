#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

class Figure
{
protected:
	Shape* _shape;
	bool _is_highlighted = false;
	bool _is_moving = false;
	RectangleShape* _rectangle = nullptr;

	Color _fillColor;
	Color _outlineColor;
	float _outlineThikness;

public:
	virtual double Area() = 0;
	virtual double Perimeter() = 0;
	virtual bool ContainsPoint(Vector2f point);
	virtual FloatRect GetGlobalBounds();
	virtual Vector2f GetPosition();

	virtual std::string GetType() = 0;

	void virtual Draw(RenderWindow& window);
	virtual void SetFillColor(Color color);
	virtual void SetOutlineColor(Color color);
	virtual void SetOutlineThickness(float thickness);
	virtual void SetPosition(Vector2f position);

	virtual Color GetFillColor();
	virtual Color GetOutlineColor();
	virtual float GetOutlineThickness();

	virtual void Highlight();
	virtual bool IsHighlighted();

	Shape* GetShape();


};


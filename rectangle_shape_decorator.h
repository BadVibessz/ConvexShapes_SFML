#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;

class RectangleShapeDecorator
{
	RectangleShape* _rectangle;

public:
	RectangleShapeDecorator(RectangleShape* rectangle) : _rectangle(rectangle) {  }

};


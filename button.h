#pragma once
#include <SFML/Graphics.hpp>
#include "command.h"


using namespace std;
using namespace sf;

class Command;

class Button
{
private:
	RectangleShape _bounds;
	Text _text;
	Font _font;

	Command* _command;

	Color _fillColor;
	Color _outlineColor;
	Color _textColor;
	float _outlineThickness;

	bool _isHighlighted = false;
	bool _isPressed = false;

public:
	Button(Vector2f position,Vector2f size,
		Color fillColor = Color::White, Color outlineColor = Color::Black,
		float outlineThickness = 1, string text = "", Color textColor = Color::Black,
		int textSize = 0, Command* command = nullptr
	);

	void Render(RenderWindow& window);
	void SetCommand(Command* command);
	bool Contains(Vector2f point);
	void Highlight(); // todo: при наведении выделять кнопку
	void UnHighlight();
	bool IsHighlighted();
	bool IsPressed();
	void PressButton(); // TODO: сделать анимацию нажатия
	void UnpressButton();

	string GetCommandName();



};


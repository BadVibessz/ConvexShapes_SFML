#include "button.h"

Button::Button(Vector2f position, Vector2f size, Color fillColor, Color outlineColor,
	float outlineThickness, string text, Color textColor, int textSize, Command* command)
{
	// TODO: CHANGE!! (too similar)

	_bounds.setPosition(position);
	_bounds.setSize(size);
	_bounds.setFillColor(fillColor);
	_bounds.setOutlineColor(outlineColor);
	_bounds.setOutlineThickness(outlineThickness);

	if (_font.loadFromFile("Arial.ttf"))
	{
		_text.setFont(_font);
		_text.setString(text);
		_text.setFillColor(textColor);
		_text.setCharacterSize(textSize);
		FloatRect rect = _text.getGlobalBounds();
		Vector2f offsetText;
		offsetText.x = (size.x - rect.width) / 2;
		offsetText.y = (size.y - rect.height) / 2;
		_text.setPosition({ position.x + offsetText.x, position.y + offsetText.y });
	}

	_fillColor = fillColor;
	_outlineColor = outlineColor;
	_textColor = textColor;
	_outlineThickness = outlineThickness;

	this->SetCommand(command);

	if (this->_command->GetName() == "DraggAndDropCommand")
		this->_isPressed = true;

}

void Button::Render(RenderWindow& window) // todo: не работает текст??
{
	window.draw(_bounds);

	_font.loadFromFile("Arial.ttf"); // todo: костыль, _font ломается после выхода из конструктора почему-то
	_text.setFont(_font);

	window.draw(_text);
}

void Button::SetCommand(Command* command)
{
	this->_command = command;
}

bool Button::Contains(Vector2f point)
{
	return this->_bounds.getGlobalBounds().contains(point);
}

void Button::Highlight() // todo: сделать красивее
{
	this->_isHighlighted = true;
	this->_bounds.setOutlineColor(Color::Red);
}

void Button::UnHighlight()
{
	this->_isHighlighted = false;
	this->_bounds.setOutlineColor(_outlineColor);
}

bool Button::IsHighlighted()
{
	return this->_isHighlighted;
}

bool Button::IsPressed()
{
	return this->_isPressed;
}

void Button::PressButton()
{
	this->_isPressed = true;
	this->_bounds.setFillColor(Color(255, 89, 94));
	this->_command->Execute();
}

void Button::UnpressButton()
{
	this->_isPressed = false;
	this->_bounds.setFillColor(_fillColor);
}

string Button::GetCommandName()
{
	return this->_command->GetName();
}

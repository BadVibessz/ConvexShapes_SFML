#include "user_handler.h"
#include "change_outline_color_command.h"
#include "dragg_and_drop_command.h"
#include "fill_shape_command.h"
#include "set_outline_width_command.h"
#include "set_fill_color_command.h"
#include "set_outline_color_command.h"
#include "change_outline_width_command.h"
#include "create_rectangle_command.h"
#include "create_triangle_command.h"
#include "create_circle_command.h"

UserHandler* UserHandler::_instance;


void UserHandler::DragAndDrop()
{
	this->_state->Dragging(_instance);
}

void UserHandler::Fill()
{
	this->_state->FillingShape(_instance);
}

void UserHandler::ChangeOutlineColor()
{
	this->_state->ChangingOutlineColor(_instance);
}

void UserHandler::ChangeOutlineWitdh()
{
	this->_state->ChangingOutlineWidth(_instance);
}

void UserHandler::CreateRectangle()
{
	this->_state->CreatingRectangle(_instance);
}

void UserHandler::CreateTriangle()
{
	this->_state->CreatingTriangle(_instance);

}

void UserHandler::CreateCircle()
{
	this->_state->CreatingCircle(_instance);
}

void UserHandler::SetOutlineWidth(float thickness)
{
	this->_outlineThickness = thickness;
}

void UserHandler::DrawInterface()
{
	for (auto btn : _stateButtons)
		btn->Render(*_window);

	for (auto btn : _fillColorButtons)
		btn->Render(*_window);

	for (auto btn : _outlineColorButtons)
		btn->Render(*_window);

	for (auto btn : _outlineWidthButtons)
		btn->Render(*_window);

}

void UserHandler::SetFillingColor(Color color)
{
	this->_fillingColor = color;
}

void UserHandler::SetOutlineColor(Color color)
{
	this->_outlineColor = color;
}

Color UserHandler::GetFillingColor()
{
	return this->_fillingColor;
}

Color UserHandler::GetOutlineColor()
{
	return this->_outlineColor;
}

float UserHandler::GetOutlineWidth()
{
	return this->_outlineThickness;
}

UserHandler::UserHandler(RenderWindow* window, ToolState* state)
{
	this->_window = window;
	this->_state = state;

	Vector2f stateBtnSize(60, 30);
	float y = window->getSize().y - 40;

	// кнопки состояний
	_stateButtons.push_back(new Button(Vector2f(5, y), stateBtnSize, Color::White, Color::Black,
		1, "Drag", Color::Black, 12, new DraggAndDropCommand(this)));
	_stateButtons.push_back(new Button(Vector2f(75, y), stateBtnSize, Color::White, Color::Black,
		1, "Fill Figure", Color::Black, 12, new FillShapeCommand(this)));
	_stateButtons.push_back(new Button(Vector2f(145, y), stateBtnSize, Color::White, Color::Black,
		1, "Fill Border", Color::Black, 12, new ChangeOutlineColorCommand(this)));
	_stateButtons.push_back(new Button(Vector2f(215, y), stateBtnSize, Color::White, Color::Black,
		1, "Width Border", Color::Black, 12, new ChangeOutlineWidthCommand(this)));


	Vector2f fillColorBtnSize(30, 30);

	// кнопки цвета заливки
	_fillColorButtons.push_back(new Button(Vector2f(315, y), fillColorBtnSize, Color(0, 8, 20), Color::Black,
		1, "", Color::Black, 12, new SetFillColorCommand(this, Color(0, 8, 20, 190))));
	_fillColorButtons.push_back(new Button(Vector2f(355, y), fillColorBtnSize, Color(0, 29, 61), Color::Black,
		1, "", Color::Black, 12, new SetFillColorCommand(this, Color(0, 29, 61, 190))));
	_fillColorButtons.push_back(new Button(Vector2f(395, y), fillColorBtnSize, Color(0, 53, 102), Color::Black,
		1, "", Color::Black, 12, new SetFillColorCommand(this, Color(0, 53, 102, 190))));
	_fillColorButtons.push_back(new Button(Vector2f(435, y), fillColorBtnSize, Color(255, 195, 0), Color::Black,
		1, "", Color::Black, 12, new SetFillColorCommand(this, Color(255, 195, 0, 190))));
	_fillColorButtons.push_back(new Button(Vector2f(475, y), fillColorBtnSize, Color(255, 214, 10), Color::Black,
		1, "", Color::Black, 12, new SetFillColorCommand(this, Color(255, 214, 10, 190))));

	// кнопки цвета границы
	_outlineColorButtons.push_back(new Button(Vector2f(545, y), fillColorBtnSize, Color(243, 240, 227), Color::Black,
		1, "", Color::Black, 12, new SetOutlineColorCommand(this, Color(243, 240, 227))));
	_outlineColorButtons.push_back(new Button(Vector2f(585, y), fillColorBtnSize, Color(46, 45, 44), Color::Black,
		1, "", Color::Black, 12, new SetOutlineColorCommand(this, Color(46, 45, 44))));
	_outlineColorButtons.push_back(new Button(Vector2f(625, y), fillColorBtnSize, Color(210, 90, 87), Color::Black,
		1, "", Color::Black, 12, new SetOutlineColorCommand(this, Color(210, 90, 87))));

	// кнопки толщины границы
	_outlineWidthButtons.push_back(new Button(Vector2f(695, y), fillColorBtnSize, Color::White, Color::Black,
		1, "2px", Color::Black, 14, new SetOutlineWidthCommand(this,2)));
	_outlineWidthButtons.push_back(new Button(Vector2f(735, y), fillColorBtnSize, Color::White, Color::Black,
		1, "4px", Color::Black, 14, new SetOutlineWidthCommand(this,4)));
	_outlineWidthButtons.push_back(new Button(Vector2f(775, y), fillColorBtnSize, Color::White, Color::Black,
		1, "8px", Color::Black, 14, new SetOutlineWidthCommand(this,8)));


	// кнопки создания фигур
	_stateButtons.push_back(new Button(Vector2f(5, y - 40), stateBtnSize, Color::White, Color::Black,
		1, "Rectangle", Color::Black, 12, new CreateRectangleCommand(this)));
	_stateButtons.push_back(new Button(Vector2f(75, y - 40), stateBtnSize, Color::White, Color::Black,
		1, "Triangle", Color::Black, 12, new CreateTriangleCommand(this)));
	_stateButtons.push_back(new Button(Vector2f(145, y - 40), stateBtnSize, Color::White, Color::Black,
		1, "Circle", Color::Black, 12, new CreateCircleCommand(this)));





}

UserHandler* UserHandler::GetInstance(RenderWindow* window, ToolState* state)
{
	if (_instance == nullptr)
		_instance = new UserHandler(window, state);
	return _instance;
}

void UserHandler::ChangeState(ToolState* state)
{
	this->_state = state;
}

ToolState* UserHandler::GetState()
{
	return this->_state;
}

vector<Button*> UserHandler::GetStateButtons()
{
	return vector<Button*>(_stateButtons);
}

vector<Button*> UserHandler::GetFillColorButtons()
{
	return vector<Button*>(this->_fillColorButtons);
}

vector<Button*> UserHandler::GetOutlineColorButtons()
{
	return vector<Button*>(_outlineColorButtons);
}

vector<Button*> UserHandler::GetOutlineWidthButtons()
{
	return vector<Button*>(this->_outlineWidthButtons);
}


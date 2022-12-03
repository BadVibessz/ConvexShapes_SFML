#include "event_handler.h"
#include "rectangle_factory.h"
#include "triangle_factory.h"
#include "application_facade.h"
#include "circle_factory.h"
#include "undo_command.h"
#include "application_facade.h"
#include "save_as_command.h"
#include "txt_saver.h"
#include "binary_saver.h"
#include "delete_command.h"
#include "load_command.h"
#include "txt_loader.h"
#include "binary_loader.h"

#include <iostream>

RenderWindow* EventHandler::_window;
vector<Figure*>* EventHandler::_figures;
bool EventHandler::_is_multi_select = false;
bool EventHandler::_is_moving = false;
Figure* EventHandler::_selected_figure = nullptr;
float EventHandler::_dx = 0;
float EventHandler::_dy = 0;
vector<Button*> EventHandler::_stateButtons;
vector<Button*> EventHandler::_fillColorButtons;
vector<Button*> EventHandler::_outlineColorButtons;
vector<Button*> EventHandler::_outlineWidthButtons;


void EventHandler::SetFigures(vector<Figure*>* figures)
{
	_figures = figures;
}

void EventHandler::SetStateButtons(vector<Button*> buttons)
{
	_stateButtons = vector<Button*>(buttons);
}

void EventHandler::SetFillColorButtons(vector<Button*> buttons)
{
	_fillColorButtons = vector<Button*>(buttons);
}

void EventHandler::SetOutlineColorButtons(vector<Button*> buttons)
{
	_outlineColorButtons = vector<Button*>(buttons);
}

void EventHandler::SetOutlineWidthButtons(vector<Button*> buttons)
{
	_outlineWidthButtons = vector<Button*>(buttons);
}



void EventHandler::HighlightOnlyThisFigure(Figure* figure)
{
	figure->Highlight();
	for (auto fig : *_figures)
		if (fig->IsHighlighted() && fig != figure) fig->Highlight();
}

void EventHandler::HandleCursorInButton(Vector2f mousePos)
{
	vector<Button*> buttons;

	buttons.insert(buttons.end(), _stateButtons.begin(), _stateButtons.end());
	buttons.insert(buttons.end(), _fillColorButtons.begin(), _fillColorButtons.end());
	buttons.insert(buttons.end(), _outlineColorButtons.begin(), _outlineColorButtons.end());
	buttons.insert(buttons.end(), _outlineWidthButtons.begin(), _outlineWidthButtons.end());



	for (auto btn : buttons)
	{
		if (btn->Contains(mousePos))
			btn->Highlight();
		else if (btn->IsHighlighted())
			btn->UnHighlight();
	}


}

void EventHandler::HandleButtonPressing(Vector2f mousePos, vector<Button*> buttons)
{
	for (auto btn : buttons)
	{
		if (btn->Contains(mousePos))
		{
			if (!btn->IsPressed())
				btn->PressButton();

			for (auto b : buttons)
				if (b != btn && b->IsPressed())
					b->UnpressButton();
		}
	}
}

bool EventHandler::IsPointInButtons(Vector2f mousePos)
{
	vector<Button*> buttons;

	buttons.insert(buttons.end(), _stateButtons.begin(), _stateButtons.end());
	buttons.insert(buttons.end(), _fillColorButtons.begin(), _fillColorButtons.end());
	buttons.insert(buttons.end(), _outlineColorButtons.begin(), _outlineColorButtons.end());
	buttons.insert(buttons.end(), _outlineWidthButtons.begin(), _outlineWidthButtons.end());



	for (auto btn : buttons)
		if (btn->Contains(mousePos))
			return true;
	return false;

}


void EventHandler::HandleEvent(Event e, UserHandler* user)
{
	auto app = ApplicationFacade::GetInstance(nullptr);

	if (e.type == Event::Closed)
		_window->close();

	auto mouse_position = _window->mapPixelToCoords(Mouse::getPosition(*_window));
	//cout << "(" + to_string(mouse_position.x) + ", " + to_string(mouse_position.y) << endl;;

	// drag state сразу выделена
	if (_stateButtons[0]->IsPressed())
		_stateButtons[0]->PressButton();

	// выделяем кнопки при наведении
	HandleCursorInButton(mouse_position);

	switch (e.type)
	{
	case Event::KeyPressed:
		if (e.key.code == Keyboard::LShift)
			_is_multi_select = true;

		else if (e.key.code == Keyboard::Delete)
		{
			auto selected_figures = vector<Figure*>();
			for (auto figure : *_figures)
				if (figure->IsHighlighted()) selected_figures.push_back(figure);

			app->SaveState();
			DeleteCommand(selected_figures).Execute();
		}

		else if (Keyboard::isKeyPressed(Keyboard::LControl))
		{
			// saving
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				if (Keyboard::isKeyPressed(Keyboard::T))
					SaveAsCommand(TxtSaver::GetInstance(), "saved").Execute();

				if (Keyboard::isKeyPressed(Keyboard::B))
					SaveAsCommand(BinarySaver::GetInstance(), "saved").Execute();
			}

			// loading
			else if (Keyboard::isKeyPressed(Keyboard::L))
			{
				if (Keyboard::isKeyPressed(Keyboard::T))
					LoadCommand(TxtLoader::GetInstance(), "saved.txt").Execute();

				if (Keyboard::isKeyPressed(Keyboard::B))
					LoadCommand(BinaryLoader::GetInstance(), "saved.bin").Execute();

			}

			// undo
			else if (Keyboard::isKeyPressed(Keyboard::Z))
				UndoCommand().Execute();

			auto selected_figures = vector<Figure*>();
			for (auto figure : *_figures)
				if (figure->IsHighlighted()) selected_figures.push_back(figure);

			// grouping
			if (Keyboard::isKeyPressed(Keyboard::G) && selected_figures.size() > 1)
				FigureHandler::GroupFigures(selected_figures);

			// ungrouping
			else if (Keyboard::isKeyPressed(Keyboard::U) && selected_figures.size() == 1
				&& selected_figures.back()->GetType() == "Grouped")
				FigureHandler::UngroupFigure(((GroupedFigure*)selected_figures.back()));

		}
		break;
	case Event::KeyReleased:
		if (e.key.code == Keyboard::LShift)
			_is_multi_select = false;
		break;

	case Event::MouseButtonPressed:
		if (e.key.code == Mouse::Left)
		{
			auto state = user->GetState();

			// выделяем и двигаем фигуры
			if (state->GetName() == "DraggingState")
				for (auto figure : *_figures)
				{
					if (figure->ContainsPoint(mouse_position))
					{
						app->SaveState(true);

						if (!figure->IsHighlighted())
						{
							if (_is_multi_select)
								figure->Highlight();

							else
								HighlightOnlyThisFigure(figure);
						}

						_is_moving = true;
						_selected_figure = figure;

						_dx = mouse_position.x - _selected_figure->GetPosition().x;
						_dy = mouse_position.y - _selected_figure->GetPosition().y;


						break;
					}

				}

			// заливаем фигуру заданным цветов
			else if (state->GetName() == "FillingState")
				for (auto figure : *_figures)
				{
					if (figure->ContainsPoint(mouse_position))
					{
						FigureHandler::ChangeFigureFillColor(figure, user);
						break;
					}
				}

			// меняем цвет границы
			else if (state->GetName() == "ChangingOutlineColorState")
				for (auto figure : *_figures)
				{
					if (figure->ContainsPoint(mouse_position))
					{
						FigureHandler::ChangeFigureOutlineColor(figure, user);
						break;
					}
				}

			// меняем толщину границы
			else if (state->GetName() == "ChangingOutlineWidthState")
				for (auto figure : *_figures)
				{
					if (figure->ContainsPoint(mouse_position))
					{
						FigureHandler::ChangeFigureOutlineThickness(figure, user);
						break;
					}
				}

			// создаем прямоугольник в точке нажатия
			else if (state->GetName() == "CreatingRectangleState")
			{
				if (!IsPointInButtons(mouse_position))
					FigureHandler::CreateRectangle(mouse_position, Vector2f(100, 200),
						Color(238, 108, 77, 190), Color(0, 0, 0), 2);
			}

			// создаем треугольник в точке нажатия
			else if (state->GetName() == "CreatingTriangleState")
			{
				if (!IsPointInButtons(mouse_position))
				{
					auto p1 = mouse_position;
					auto p2 = Vector2f(p1.x + 100, p1.y);
					auto p3 = Vector2f(p1.x, p1.y + 100);

					FigureHandler::CreateTriangle(p1, p2, p3, Color(238, 108, 77, 190),
						Color(0, 0, 0), 2);
				}

			}

			// создаем круг в точке нажатия
			else if (state->GetName() == "CreatingCircleState")
			{
				if (!IsPointInButtons(mouse_position))
					FigureHandler::CreateCircle(mouse_position, 50, Color(238, 108, 77, 190),
						Color(0, 0, 0), 2);
			}

			// нажимаем кнопки состояний
			for (auto btn : _stateButtons)
			{
				if (btn->Contains(mouse_position))
				{
					if (btn->IsPressed())
					{
						btn->UnpressButton();
						_stateButtons[0]->PressButton();
					}
					else
					{
						btn->PressButton();
						if (btn != _stateButtons[0])
							_stateButtons[0]->UnpressButton();
					}


					// при отжатии кнопок должна автоматом нажаться Drag
					// отжимаем другие кнопки
					for (auto b : _stateButtons)
						if (b != btn && b->IsPressed() && b != _stateButtons[0])
							b->UnpressButton();
					break;
				}

			}

			// нажимаем кнопки выбора цвета заливки
			HandleButtonPressing(mouse_position, _fillColorButtons);

			// нажимаем кнопки выбора цвета границы 
			HandleButtonPressing(mouse_position, _outlineColorButtons);

			// нажимаем кнопки выбора цвета границы 
			HandleButtonPressing(mouse_position, _outlineWidthButtons);

		}
		break;



	case Event::MouseButtonReleased:

		_is_moving = false;
		break;

	}

	if (_is_moving)
		_selected_figure->SetPosition(Vector2f(mouse_position.x - _dx, mouse_position.y - _dy));

}

void EventHandler::SetWindow(RenderWindow* window)
{
	_window = window;
}

#include "event_handler.h"
#include "rectangle_factory.h"
#include "triangle_factory.h"
#include "application_facade.h"
#include "circle_factory.h"

RenderWindow* EventHandler::_window;
vector<Figure*> EventHandler::_figures;
bool EventHandler::_is_multi_select = false;
bool EventHandler::_is_moving = false;
Figure* EventHandler::_selected_figure = nullptr;
float EventHandler::_dx = 0;
float EventHandler::_dy = 0;
vector<Button*> EventHandler::_stateButtons;
vector<Button*> EventHandler::_fillColorButtons;
vector<Button*> EventHandler::_outlineColorButtons;
vector<Button*> EventHandler::_outlineWidthButtons;


void EventHandler::SetShapes(vector<Figure*> figures)
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
	for (auto fig : _figures)
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
	if (e.type == Event::Closed)
		_window->close();

	auto mouse_position = _window->mapPixelToCoords(Mouse::getPosition(*_window));



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

		if (Keyboard::isKeyPressed(Keyboard::LControl))
		{

			auto selected_figures = vector<Figure*>();
			for (auto figure : _figures)
				if (figure->IsHighlighted()) selected_figures.push_back(figure);

			if (Keyboard::isKeyPressed(Keyboard::G) && selected_figures.size() > 1)
			{
				auto grouped = new GroupedFigure();

				for (auto selected : selected_figures)
				{
					grouped->AddFigure(selected);
					selected->Highlight();

					auto it = find(_figures.begin(), _figures.end(), selected);

					if (it != _figures.end())
						_figures.erase(it);
				}

				_figures.push_back(grouped);
			}

			if (Keyboard::isKeyPressed(Keyboard::U) && selected_figures.size() != 0)
			{
				if (selected_figures.size() == 1 && selected_figures.back()->GetType() == "Grouped")
				{
					auto grouped_figures = ((GroupedFigure*)selected_figures.back())->GetFigures();

					selected_figures.back()->Highlight();

					auto it = find(_figures.begin(), _figures.end(), selected_figures.back());
					if (it != _figures.end())
						_figures.erase(it);

					for (auto grouped_figure : grouped_figures)
						_figures.push_back(grouped_figure);
				}
			}

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
				for (auto figure : _figures)
				{
					if (figure->ContainsPoint(mouse_position))
					{
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
				for (auto figure : _figures)
				{
					if (figure->ContainsPoint(mouse_position))
					{
						figure->SetFillColor(user->GetFillingColor());

						if (!figure->IsHighlighted())
							HighlightOnlyThisFigure(figure);


						break;
					}
				}

			// меняем цвет границы
			else if (state->GetName() == "ChangingOutlineColorState")
				for (auto figure : _figures)
				{
					if (figure->ContainsPoint(mouse_position))
					{
						figure->SetOutlineColor(user->GetOutlineColor());

						if (!figure->IsHighlighted())
							HighlightOnlyThisFigure(figure);


						break;
					}
				}

			// меняем толщину границы
			else if (state->GetName() == "ChangingOutlineWidthState")
				for (auto figure : _figures)
				{
					if (figure->ContainsPoint(mouse_position))
					{
						figure->SetOutlineThickness(user->GetOutlineWidth());

						if (!figure->IsHighlighted())
							HighlightOnlyThisFigure(figure);
						break;
					}
				}

			// создаем прямоугольник в точке нажатия
			else if (state->GetName() == "CreatingRectangleState")
			{
				if (!IsPointInButtons(mouse_position))
				{
					auto rect = RectangleFactory(mouse_position, Vector2f(100, 200),
						Color(238, 108, 77, 190), Color(0, 0, 0), 2).GetFigure();
					ApplicationFacade::GetInstance(_window)->AddFigure(rect);
					_figures.push_back(rect);
				}
			}

			// создаем треугольник в точке нажатия
			else if (state->GetName() == "CreatingTriangleState")
			{
				if (!IsPointInButtons(mouse_position))
				{
					auto p1 = mouse_position;
					auto p2 = Vector2f(p1.x + 100, p1.y);
					auto p3 = Vector2f(p1.x, p1.y + 100);

					auto triag = TriangleFactory(p1, p2, p3, Color(238, 108, 77, 190),
						Color(0, 0, 0), 2).GetFigure();
					ApplicationFacade::GetInstance(_window)->AddFigure(triag);
					_figures.push_back(triag);
				}

			}

			// создаем круг в точке нажатия
			else if (state->GetName() == "CreatingCircleState")
			{
				if (!IsPointInButtons(mouse_position))
				{


					auto circle = CircleFactory(mouse_position, 50, Color(238, 108, 77, 190),
						Color(0, 0, 0), 2).GetFigure();
					ApplicationFacade::GetInstance(_window)->AddFigure(circle);
					_figures.push_back(circle);
				}

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

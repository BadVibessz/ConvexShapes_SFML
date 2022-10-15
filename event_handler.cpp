#include "event_handler.h"

RenderWindow* EventHandler::_window;
vector<Figure*> EventHandler::_figures;
bool EventHandler::_is_multi_select = false;
bool EventHandler::_is_moving = false;
Figure* EventHandler::_selected_figure = nullptr;
float EventHandler::_dx = 0;
float EventHandler::_dy = 0;


void EventHandler::SetShapes(vector<Figure*> figures)
{
	_figures = figures;
}

void EventHandler::HandleEvent(Event e, Drawer drawer)
{
	auto mouse_position = _window->mapPixelToCoords(Mouse::getPosition(*_window));


	//float dx = 0, dy = 0;

	auto selected_figures = vector<Figure*>();
	for (auto figure : _figures)
		if (figure->IsHighlighted()) selected_figures.push_back(figure);

	switch (e.type)
	{
	case Event::KeyPressed:
		if (e.key.code == Keyboard::LShift)
			_is_multi_select = true;

		if (Keyboard::isKeyPressed(Keyboard::LControl))
		{
			if (Keyboard::isKeyPressed(Keyboard::G) && selected_figures.size() > 1)
			{
				auto grouped = new GroupedFigure();

				if (selected_figures.size() > 1)
				{
					for (auto selected : selected_figures)
					{
						grouped->AddFigure(selected);
						selected->Highlight();

						auto it = find(_figures.begin(), _figures.end(), selected);

						if (it != _figures.end())
							_figures.erase(it);
					}
				}
				_figures.push_back(grouped);
			}

			if (Keyboard::isKeyPressed(Keyboard::U) && selected_figures.size() != 0)
			{
				if (selected_figures.size() == 1 && selected_figures.back()->GetType() == "Grouped")
				{
					auto grouped_figures = ((GroupedFigure*)selected_figures.back())->GetFigures();

					auto it = find(_figures.begin(), _figures.end(), selected_figures.back());

					selected_figures.back()->Highlight();

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
			for (auto figure : _figures)
			{

				if (figure->ContainsPoint(mouse_position))
				{
					if (!_is_multi_select)
						for (auto fig : _figures)
							if (fig->IsHighlighted() && fig != figure) fig->Highlight();

					figure->Highlight();
					_is_moving = true;

					_selected_figure = figure;

					_dx = mouse_position.x - _selected_figure->GetPosition().x;
					_dy = mouse_position.y - _selected_figure->GetPosition().y;

					break;
				}
			}

		}
		break;


	case Event::MouseButtonReleased:
		_is_moving = false;
		break;

	}

	if (_is_moving && _selected_figure != nullptr && _selected_figure->IsHighlighted())
	{
		_selected_figure->SetPosition(Vector2f(mouse_position.x - _dx, mouse_position.y - _dy));
	}
}

void EventHandler::SetWindow(RenderWindow* window)
{
	_window = window;
}

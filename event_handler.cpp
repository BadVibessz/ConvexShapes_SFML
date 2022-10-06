#include "event_handler.h"

RenderWindow* EventHandler::_window;
vector<Figure*> EventHandler::_figures;
bool EventHandler::_is_multi_select = false;
bool EventHandler::_is_moving = false;
Figure* EventHandler::_selected_figure = nullptr;

void EventHandler::SetShapes(vector<Figure*> figures)
{
	_figures = figures;
}

void EventHandler::HandleEvent(Event e)
{
	auto mouse_position = _window->mapPixelToCoords(Mouse::getPosition(*_window));
	float dx = 0, dy = 0;

	switch (e.type)
	{
	case Event::KeyPressed:
		if (e.key.code == Keyboard::LShift)
			_is_multi_select = true;

		if (Keyboard::isKeyPressed(Keyboard::LControl))
		{
			if (Keyboard::isKeyPressed(Keyboard::G))
			{
				auto grouped = new GroupedFigure();
				auto selected_figures = vector<Figure*>();

				for (auto figure : _figures)
					if (figure->IsHighlighted()) selected_figures.push_back(figure);

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

			if (Keyboard::isKeyPressed(Keyboard::U))
			{
				auto selected_figures = vector<Figure*>();
				for (auto figure : _figures)
					if (figure->IsHighlighted()) selected_figures.push_back(figure);

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
				if (figure->ContainsPoint(Vector2f(mouse_position.x, mouse_position.y)))
				{
					if (!_is_multi_select)
						for (auto fig : _figures)
							if (fig->IsHighlighted() && fig != figure) fig->Highlight();

					figure->Highlight();
					_is_moving = true;

					if (figure->GetType() == "Grouped")
						_selected_figure = ((GroupedFigure*)figure)->
						GetFigureThatContainsPoint(Vector2f(mouse_position.x, mouse_position.y));
					else _selected_figure = figure;


					dx = mouse_position.x - _selected_figure->GetShape()->getPosition().x;
					dy = mouse_position.y - _selected_figure->GetShape()->getPosition().y;

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
		//auto currMouseLoc = _window->mapPixelToCoords(Mouse::getPosition());

		/*float DX = currMouseLoc.x - mouse_position.x;
		float DY = currMouseLoc.y - mouse_position.y;*/

		//auto pos = _selected_figure->GetShape()->getPosition();

		_selected_figure->SetPosition(Vector2f(mouse_position.x - dx, mouse_position.y - dy));
		//_selected_figure->SetPosition(Vector2f(DX, DY));
		//_selected_figure->SetPosition(_window->mapPixelToCoords(mouse_position));
	}
}

void EventHandler::SetWindow(RenderWindow* window)
{
	_window = window;
}

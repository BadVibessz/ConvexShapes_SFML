#include "application_facade.h"

ApplicationFacade* ApplicationFacade::_instance;

ApplicationFacade::ApplicationFacade(int width, int height)
{
	_window = new RenderWindow(VideoMode(width, height), "works");
	_window->setFramerateLimit(60);

	ContextSettings settings;
	settings.antialiasingLevel = 8;


	this->_drawer = Drawer(_window);
	EventHandler::SetWindow(_window);

	this->_userHandler = UserHandler::GetInstance(_window, new DraggingState());

	EventHandler::SetStateButtons(_userHandler->GetStateButtons());
	EventHandler::SetFillColorButtons(_userHandler->GetFillColorButtons());
	EventHandler::SetOutlineColorButtons(_userHandler->GetOutlineColorButtons());
	EventHandler::SetOutlineWidthButtons(_userHandler->GetOutlineWidthButtons());
}

ApplicationFacade::ApplicationFacade(RenderWindow* window)
	: ApplicationFacade(window->getSize().x, window->getSize().y)
{
}

vector<Figure*> ApplicationFacade::CopyFigures(vector<Figure*> figures)
{
	auto vec = vector<Figure*>();
	for (auto figure : _figures)
	{
		if (figure->GetType() == "Circle")
		{
			auto circle = ((CircleDecorator*)figure);
			vec.push_back(new CircleDecorator(circle));
		}
		else if (figure->GetType() == "Rectangle")
		{
			auto rect = ((RectangleDecorator*)figure);
			vec.push_back(new RectangleDecorator(rect));
		}
		else if (figure->GetType() == "Triangle")
		{
			auto triag = ((TriangleDecorator*)figure);
			vec.push_back(new TriangleDecorator(triag));
		}
	}

	return vec;
}

void ApplicationFacade::Run()
{
	ReadInput();
	SaveData();

	while (_window->isOpen())
	{
		Event event;
		while (_window->pollEvent(event))
			HandleEvent(event);

		DrawInput();
	}

}

void ApplicationFacade::ReadInput()
{
	this->_figures = FileManager::ReadInput();
	EventHandler::SetShapes(_figures);
}

void ApplicationFacade::SaveData()
{
	FileManager::SaveData(this->_figures);

}

void ApplicationFacade::HandleEvent(Event e)
{
	EventHandler::HandleEvent(e, _userHandler);
}

void ApplicationFacade::DrawInput()
{
	_window->clear(Color(255, 255, 255));
	//_drawer.DrawAxis(Color::Black);
	_drawer.DrawFigures(_figures);
	_userHandler->DrawInterface();


	_window->display();
}

void ApplicationFacade::AddFigure(Figure* figure)
{
	this->_figures.push_back(figure);
}

ApplicationFacade* ApplicationFacade::GetInstance(int width, int height)
{
	if (_instance == nullptr)
		_instance = new ApplicationFacade(width, height);
	return _instance;
}

ApplicationFacade* ApplicationFacade::GetInstance(RenderWindow* window)
{
	if (_instance == nullptr)
		_instance = new ApplicationFacade(window);
	return _instance;

}


AppMemento ApplicationFacade::SaveState()
{

	auto memento = AppMemento(CopyFigures(_figures));
	this->_history.push(memento);

	return memento;
}

void ApplicationFacade::RestoreState(AppMemento memento)
{
	auto f = memento.GetFigures();
	this->_figures = memento.GetFigures();
	EventHandler::SetShapes(_figures);

}

void ApplicationFacade::Accept(Visitor* visitor, Figure* figure)
{
	SaveState();
	visitor->VisitFigure(figure);
}

void ApplicationFacade::Undo()
{
	if (_history.size() == 0) return;
	RestoreState(_history.top());
	_history.pop();
}

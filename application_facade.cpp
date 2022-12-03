#include "application_facade.h"
#include "my_extensions.h"

ApplicationFacade* ApplicationFacade::_instance;

bool ApplicationFacade::AreFiguresEqual(Figure* f1, Figure* f2)
{
	if (f1->GetType() != f2->GetType()) return false;

	string type = f1->GetType();


	bool posFlag = f1->GetPosition() == f2->GetPosition();
	bool fillFlag = f1->GetFillColor() == f2->GetFillColor();
	Color c1 = f1->GetFillColor();
	Color c2 = f2->GetFillColor();
	float th1 = f1->GetOutlineThickness();
	float th2 = f2->GetOutlineThickness();
	bool outColFlag = f1->GetOutlineColor() == f2->GetOutlineColor();
	bool outThicFlag = f1->GetOutlineThickness() == f2->GetOutlineThickness();

	bool flag = f1->GetPosition() == f2->GetPosition()
		&& f1->GetFillColor() == f2->GetFillColor()
		&& f1->GetOutlineColor() == f2->GetOutlineColor()
		&& f1->GetOutlineThickness() == f2->GetOutlineThickness();

	if (flag == false) return false;

	if (type == "Rectangle")
	{
		auto r1 = (RectangleDecorator*)f1;
		auto r2 = (RectangleDecorator*)f2;

		flag = r1->GetSize() == r1->GetSize();

	}

	else if (type == "Triangle")
	{
		auto t1 = (TriangleDecorator*)f1;
		auto t2 = (TriangleDecorator*)f2;

		flag = t1->GetPoint(0) == t2->GetPoint(0)
			&& t1->GetPoint(1) == t2->GetPoint(1)
			&& t1->GetPoint(2) == t2->GetPoint(2);
	}
	else if (type == "Circle")
	{
		auto c1 = (CircleDecorator*)f1;
		auto c2 = (CircleDecorator*)f2;

		flag = c1->GetRadius() == c2->GetRadius();
	}

	else if (type == "Grouped")
	{
		auto g1 = (GroupedFigure*)f1;
		auto g2 = (GroupedFigure*)f2;

		flag = g1->GetFigures() == g2->GetFigures(); // TODO!!!
	}
	return flag;
}

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





void ApplicationFacade::Run()
{
	ReadInput();
	SaveState();
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

	EventHandler::SetFigures(&_figures);

	FigureHandler::SetFigures(&_figures);
	FigureHandler::SetApplication(_instance);
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

void ApplicationFacade::RemoveFigure(Figure* figure)
{
	auto it = find(_figures.begin(), _figures.end(), figure);

	if (it != _figures.end())
		_figures.erase(it);

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


bool ApplicationFacade::IsJustClick()
{
	//if (this->_userHandler->GetState()->GetName() != "DraggingState") return false;
	if (_history.size() == 0) return false;

	auto lastFigures = _history.top().GetFigures();

	if (lastFigures.size() != _figures.size()) return false;

	for (int i = 0; i < _figures.size(); i++)
		if (_figures[i]->GetPosition() != lastFigures[i]->GetPosition())
			return false;

	return true;
}

AppMemento ApplicationFacade::SaveState(bool isDragging)
{
	auto memento = AppMemento(MyExtensions::CopyFigures(_figures));

	// TODO:
	if (isDragging)
	{
		if (!IsJustClick())
			this->_history.push(memento);
	}
	else
		this->_history.push(memento);

	return memento;
}

void ApplicationFacade::RestoreState(AppMemento memento)
{
	this->_figures = memento.GetFigures();
}

void ApplicationFacade::RestoreState(vector<Figure*> figures)
{
	SaveState();
	this->_figures = figures;
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

void ApplicationFacade::SaveAs(Saver* saver, string filename)
{
	saver->Save(filename, _figures);
}

void ApplicationFacade::DeleteFigures(vector<Figure*> figures)
{
	for (auto figure : figures)
		RemoveFigure(figure);
}

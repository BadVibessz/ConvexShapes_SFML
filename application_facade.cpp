#include "application_facade.h"

ApplicationFacade* ApplicationFacade::_instance;

ApplicationFacade::ApplicationFacade(RenderWindow* window)
{
	this->_window = window;
	this->_drawer = Drawer(window);
	EventHandler::SetWindow(window);

	this->_userHandler = UserHandler::GetInstance(window, new DraggingState());

	EventHandler::SetStateButtons(_userHandler->GetStateButtons());
	EventHandler::SetFillColorButtons(_userHandler->GetFillColorButtons());
	EventHandler::SetOutlineColorButtons(_userHandler->GetOutlineColorButtons());
	EventHandler::SetOutlineWidthButtons(_userHandler->GetOutlineWidthButtons());
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
	_drawer.DrawAxis(Color::Black);
	_drawer.DrawFigures(_figures);
	_userHandler->DrawInterface();


	_window->display();
}

void ApplicationFacade::AddFigure(Figure* figure)
{
	this->_figures.push_back(figure);
}

ApplicationFacade* ApplicationFacade::GetInstance(RenderWindow* window)
{
	if (_instance == nullptr)
		_instance = new ApplicationFacade(window);
	return _instance;

}

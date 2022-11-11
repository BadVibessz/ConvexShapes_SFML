#pragma once
#include <vector>
#include "figure.h"
#include <SFML/Graphics.hpp>
#include "drawer.h"
#include "event_handler.h"
#include "user_handler.h"
#include "app_memento.h"

#include "changing_outline_color_state.h"
#include "dragging_state.h"
#include "filling_state.h"
#include "setting_outline_width_state.h"

#include "circle_decorator.h"
#include "rectangle_decorator.h"
#include "triangle_decorator.h"

#include "visitor.h"

#include <stack>

using namespace std;
using namespace sf;

class ApplicationFacade // singleton
{

private:
	static ApplicationFacade* _instance;
	vector<Figure*> _figures;
	RenderWindow* _window;
	Drawer _drawer;
	UserHandler* _userHandler;
	stack<AppMemento> _history = stack<AppMemento>();


	ApplicationFacade(RenderWindow* window);

	vector<Figure*> CopyFigures(vector<Figure*> figures);

public:
	void ReadInput();
	void SaveData();
	void HandleEvent(Event e);
	void DrawInput();
	void AddFigure(Figure* figure);
	static ApplicationFacade* GetInstance(RenderWindow* window);

	void Accept(Visitor* visitor, Figure* figure);

	AppMemento SaveState();
	void RestoreState(AppMemento memento);

	void Undo();






};


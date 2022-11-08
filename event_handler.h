#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "figure.h"
#include "grouped_figure.h"
#include "drawer.h"
#include "user_handler.h"
#include "fill_visitor.h"


using namespace sf;
using namespace std;

class FillVisitor;
class Button;

class EventHandler
{
private:
	static vector<Figure*> _figures;
	static RenderWindow* _window;
	static bool _is_multi_select;
	static bool _is_moving;
	static Figure* _selected_figure;
	static float _dx, _dy;
	static vector<Button*> _stateButtons;
	static vector<Button*> _fillColorButtons;
	static vector<Button*> _outlineColorButtons;
	static vector<Button*> _outlineWidthButtons;

	static void HighlightOnlyThisFigure(Figure* figure);
	static void HandleCursorInButton(Vector2f mousePos);
	static void HandleButtonPressing(Vector2f mousePos, vector<Button*> buttons);
	static bool IsPointInButtons(Vector2f mousePos);

public:
	static void SetShapes(vector <Figure*> figures);
	static void HandleEvent(Event e, UserHandler* user);

	static void SetWindow(RenderWindow* window);

	static void SetStateButtons(vector<Button*> buttons);
	static void SetFillColorButtons(vector<Button*> buttons);
	static void SetOutlineColorButtons(vector<Button*> buttons);
	static void SetOutlineWidthButtons(vector<Button*> buttons);

};

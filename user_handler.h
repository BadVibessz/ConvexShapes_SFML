#pragma once
#include <SFML/Graphics.hpp>
#include "tool_state.h"
#include "button.h"


using namespace std;
using namespace sf;

class ToolState;
class Button;

class UserHandler // singleton
{
private:
	static UserHandler* _instance;
	RenderWindow* _window;
	ToolState* _state;
	UserHandler(RenderWindow* window, ToolState* state);
	vector<Button*> _stateButtons;
	vector<Button*> _fillColorButtons;
	vector<Button*> _outlineColorButtons;
	vector<Button*> _outlineWidthButtons;
	
	Color _fillingColor = Color::Blue;
	Color _outlineColor = Color::Yellow;

	float _outlineThickness = 2;

public:
	static UserHandler* GetInstance(RenderWindow* window, ToolState* state);
	void ChangeState(ToolState* state);
	ToolState* GetState();
	vector<Button*> GetStateButtons();
	vector<Button*> GetFillColorButtons();
	vector<Button*> GetOutlineColorButtons();
	vector<Button*> GetOutlineWidthButtons();

	void DragAndDrop();
	void Fill();
	void ChangeOutlineColor();
	void ChangeOutlineWitdh();

	void CreateRectangle();
	void CreateTriangle();
	void CreateCircle();

	void DrawInterface();

	void SetFillingColor(Color color);
	void SetOutlineColor(Color color);

	void SetOutlineWidth(float thickness);


	Color GetFillingColor();
	Color GetOutlineColor();
	float GetOutlineWidth();




};


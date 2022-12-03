#pragma once
#include <vector>
#include "figure.h"
#include "grouped_figure.h"
#include "application_facade.h"
#include "fill_visitor.h"
#include "change_outline_color_visitor.h"
#include "change_outline_width_visitor.h"
#include "user_handler.h"
#include "circle_factory.h"
#include "rectangle_factory.h"
#include "triangle_factory.h"

class ApplicationFacade;

using namespace std;
static class FigureHandler
{
private:
	static vector<Figure*>* _figures;
	static ApplicationFacade* _app;
	static void HighlightOnlyThisFigure(Figure* figure);


public:
	static void SetFigures(vector<Figure*>* figures);
	static void SetApplication(ApplicationFacade* app);
	static void GroupFigures(vector<Figure*> figures);
	static void UngroupFigure(GroupedFigure* groupedFigure);
	static void ChangeFigureFillColor(Figure* figure, UserHandler* user);
	static void ChangeFigureOutlineColor(Figure* figure, UserHandler* user);
	static void ChangeFigureOutlineThickness(Figure* figure, UserHandler* user);
	static void CreateRectangle(Vector2f position, Vector2f size,
		Color fillColor, Color outlineColor, float outlineThickness);
	static void CreateTriangle(Vector2f p1, Vector2f p2, Vector2f p3,
		Color fillColor, Color outlineColor, float outlineThickness);

	static void CreateCircle(Vector2f position, float radius,
		Color fillColor, Color outlineColor, float outlineThickness);


};


#include "figure_handler.h"

vector<Figure*>* FigureHandler::_figures = nullptr;
ApplicationFacade* FigureHandler::_app = nullptr;


void FigureHandler::HighlightOnlyThisFigure(Figure* figure)
{
	figure->Highlight();
	for (auto fig : *_figures)
		if (fig->IsHighlighted() && fig != figure) fig->Highlight();

}

void FigureHandler::SetFigures(vector<Figure*>* figures)
{
	_figures = figures;
}

void FigureHandler::SetApplication(ApplicationFacade* app)
{
	if (_app == nullptr) _app = app;
}

void FigureHandler::GroupFigures(vector<Figure*> figures)
{
	_app->SaveState();

	auto grouped = new GroupedFigure();

	for (auto selected : figures)
	{
		grouped->AddFigure(selected);
		selected->Highlight();

		auto it = find(_figures->begin(), _figures->end(), selected);

		if (it != _figures->end())
			_figures->erase(it);
	}

	_figures->push_back(grouped);

}

void FigureHandler::UngroupFigure(GroupedFigure* groupedFigure)
{
	_app->SaveState();
	groupedFigure->Highlight();
	auto figures = groupedFigure->GetFigures();

	auto it = find(_figures->begin(), _figures->end(), groupedFigure);
	if (it != _figures->end())
		_figures->erase(it);

	for (auto figure : figures)
		_figures->push_back(figure);

}

void FigureHandler::ChangeFigureFillColor(Figure* figure, UserHandler* user)
{

	_app->Accept(new FillVisitor(user->GetFillingColor()), figure);

	if (!figure->IsHighlighted())
		HighlightOnlyThisFigure(figure);

}

void FigureHandler::ChangeFigureOutlineColor(Figure* figure, UserHandler* user)
{
	_app->Accept(new ChangeOutlineColorVisitor(user->GetOutlineColor()), figure);

	if (!figure->IsHighlighted())
		HighlightOnlyThisFigure(figure);

}

void FigureHandler::ChangeFigureOutlineThickness(Figure* figure, UserHandler* user)
{
	_app->Accept(new ChangeOutlineWidthVisitor(user->GetOutlineWidth()), figure);

	if (!figure->IsHighlighted())
		HighlightOnlyThisFigure(figure);
}

void FigureHandler::CreateRectangle(Vector2f position, Vector2f size,
	Color fillColor, Color outlineColor, float outlineThickness)
{

	_app->SaveState();

	auto rect = RectangleFactory(position, size,
		fillColor, outlineColor, outlineThickness).GetFigure();
	_figures->push_back(rect);
}

void FigureHandler::CreateTriangle(Vector2f p1, Vector2f p2, Vector2f p3,
	Color fillColor, Color outlineColor, float outlineThickness)
{
	_app->SaveState();

	auto triag = TriangleFactory(p1, p2, p3, fillColor,
		outlineColor, outlineThickness).GetFigure();
	_figures->push_back(triag);
}

void FigureHandler::CreateCircle(Vector2f position, float radius,
	Color fillColor, Color outlineColor, float outlineThickness)
{
	_app->SaveState();

	auto circle = CircleFactory(position, radius, fillColor,
		outlineColor, outlineThickness).GetFigure();
	_figures->push_back(circle);

}

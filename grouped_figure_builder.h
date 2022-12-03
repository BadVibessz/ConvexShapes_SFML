#pragma once
#include "figure_builder.h"
#include "grouped_figure.h"

class GroupedFigureBuilder : public FigureBuilder
{
private:
	GroupedFigure* _groupedFigure = new GroupedFigure();

public:
	GroupedFigureBuilder();

	FigureBuilder* Build() override;
	FigureBuilder* SetPosition(Vector2f position) override;
	GroupedFigureBuilder* AddFigure(Figure* figure);
	FigureBuilder* SetFillColor(Color color) override;
	FigureBuilder* SetOutlineColor(Color color) override;
	FigureBuilder* SetOutlineThickness(float thickness) override;
};


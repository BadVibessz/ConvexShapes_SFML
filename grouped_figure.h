#pragma once
#include "figure.h"
#include <vector>

using namespace std;
using namespace sf;

class GroupedFigure : public Figure
{
private:
	vector<Figure*> _figures;

public:

	double  Area() override;
	double Perimeter() override;
	std::string GetType() override;
	void AddFigure(Figure* figure);
	void DeleteFigure(Figure* figure);
	vector<Figure*> GetShapes();
	void Highlight() override;
	bool IsHighlighted() override;

};


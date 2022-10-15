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
	vector<Figure*> GetFigures();

	void SetPosition(Vector2f position) override;
	void Highlight() override;
	bool IsHighlighted() override;
	bool ContainsPoint(Vector2f point) override;

	FloatRect GetGlobalBounds() override;
	Vector2f GetPosition() override;

	Figure* GetFigureThatContainsPoint(Vector2f point);

};

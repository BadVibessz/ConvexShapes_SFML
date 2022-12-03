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
	GroupedFigure() = default;
	GroupedFigure(GroupedFigure* other);

	double  Area() override;
	double Perimeter() override;
	string GetType() override;

	void AddFigure(Figure* figure);
	void DeleteFigure(Figure* figure);
	vector<Figure*> GetFigures();

	void Draw(RenderWindow& window) override;

	void SetPosition(Vector2f position) override;
	void Highlight() override;
	bool IsHighlighted() override;
	bool ContainsPoint(Vector2f point) override;
	void SetFillColor(Color color) override;

	 void SetOutlineColor(Color color) override;
	 void SetOutlineThickness(float thickness) override;

	FloatRect GetGlobalBounds() override;
	Vector2f GetPosition() override;

	Figure* GetFigureThatContainsPoint(Vector2f point);

};


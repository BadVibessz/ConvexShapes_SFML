#include "saver.h"

string Saver::SerializeFigureToString(Figure* figure)
{
	string serialized = "";

	if (figure->GetType() == "Rectangle")
	{
		auto rect = (RectangleDecorator*)figure;

		serialized.append("Rectangle ");
		serialized.append(to_string(rect->GetPosition().x) // position
			+ ' ' + to_string(rect->GetPosition().y) + ' ');

		serialized.append(to_string(rect->GetSize().x) // size
			+ ' ' + to_string(rect->GetSize().y) + ' ');

		auto zzzz = rect->GetFillColor().toInteger();
		serialized.append(to_string(rect->GetFillColor().toInteger()) + ' '); // fill color
		serialized.append(to_string(rect->GetOutlineColor().toInteger()) + ' '); // outline color
		serialized.append(to_string(rect->GetOutlineThickness())); // outline thickness


	}
	else if (figure->GetType() == "Triangle")
	{
		auto triag = (TriangleDecorator*)figure;

		serialized.append("Triangle ");

		for (int i = 0; i < 3; i++) // points
			serialized.append(
				to_string(triag->GetPoint(i).x)
				+ ' '
				+ to_string(triag->GetPoint(i).y)
				+ ' '
			);

		serialized.append(to_string(triag->GetPosition().x) // position
			+ ' ' + to_string(triag->GetPosition().y) + ' ');

		serialized.append(to_string(triag->GetFillColor().toInteger()) + ' ');
		serialized.append(to_string(triag->GetOutlineColor().toInteger()) + ' ');
		serialized.append(to_string(triag->GetOutlineThickness()));
	}
	else if (figure->GetType() == "Circle")
	{

		auto circle = (CircleDecorator*)figure;

		serialized.append("Circle ");

		serialized.append(to_string(circle->GetPosition().x) // position
			+ ' ' + to_string(circle->GetPosition().y) + ' ');

		serialized.append(to_string(circle->GetRadius()) + ' '); // radius

		serialized.append(to_string(circle->GetFillColor().toInteger()) + ' ');
		serialized.append(to_string(circle->GetOutlineColor().toInteger()) + ' ');
		serialized.append(to_string(circle->GetOutlineThickness()));

	}
	else if (figure->GetType() == "Grouped") // TODO:
	{
		auto grouped = (GroupedFigure*)figure;

		serialized.append("GroupedStarted\n");

		for (auto figure : grouped->GetFigures())
			serialized.append(SerializeFigure(figure) + '\n');

		serialized.append("GroupedEnded");

	}

	return serialized;
}

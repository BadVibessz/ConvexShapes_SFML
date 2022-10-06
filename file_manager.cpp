#include "file_manager.h"
#include "my_extensions.h"
#include <iostream>
#include "circle_factory.h"
#include "rectangle_factory.h"
#include "triangle_factory.h"

#include "triangle_decorator.h"

vector<Figure*> FileManager::ReadInput()
{

	ifstream input;
	input.open(path_to_input);

	auto data = vector<vector<string>>();

	if (input.is_open())
	{
		string line;

		while (getline(input, line))
			if (line[0] != ';')
				data.push_back(MyExtensions::Split(line, ' '));
	}

	auto result = vector<Figure*>();
	int count;
	for (auto v : data)
	{
		if (v[0] == "TRIANGLE:") count = 3;
		if (v[0] == "RECTANGLE:") count = 2;
		if (v[0] == "CIRCLE:") count = 1;

		auto points = vector<Vector2f>();
		for (int i = 0; i < count; i++)
		{
			auto coord = v[i + 1].substr(v[i + 1].find('=') + 1);
			auto temp = MyExtensions::Split(coord, ',');
			points.push_back(Vector2f(stoi(temp[0]), stoi(temp[1])));
		}

		Figure* figure = nullptr;
		if (count == 1)
		{
			auto rad = MyExtensions::Split(v[2].substr(v[2].find('=') + 1), ';');
			figure = CircleFactory(points[0], stoi(rad[0]), Color(255, 0, 0, 100)).GetFigure();
		}
		else if (count == 2)
		{
			auto size = Vector2f(points[0].y, points[1].x);
			figure = RectangleFactory(points[0], size, Color(120, 255, 0, 100)).GetFigure();
		}
		else if (count == 3)
			figure = TriangleFactory(points[0], points[1], points[2], Color(255, 0, 0, 100)).GetFigure();

		result.push_back(figure);
	}

	return result;

}

void FileManager::SaveData(vector<Figure*> figures)
{
	ofstream output;
	output.open(path_to_output);

	for (auto figure : figures)
		output << figure->GetType() + ": Perimeter = " +
		to_string(figure->Perimeter()) +
		+" Area = " + to_string(figure->Area()) << endl;
}

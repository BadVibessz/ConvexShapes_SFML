#include "drawer.h"
#include "file_manager.h"
#include "my_extensions.h"

using namespace std;

Drawer::Drawer()
{
}

Drawer::Drawer(RenderWindow* window, int width, int height)
{
	this->_window = window;
	this->width = width;
	this->height = height;
}

void Drawer::DrawLine(Point p1, Point p2, Color color)
{
	Vertex line[] =
	{
		Vertex(Vector2f(p1.x, p1.y),color),
		Vertex(Vector2f(p2.x, p2.y),color)
	};
	_window->draw(line, 2, Lines);
}

void Drawer::DrawAxis(Color color)
{
	DrawLine(Point(0, height / 2), Point(width, height / 2), color);
	DrawLine(Point(width / 2, 0), Point(width / 2, height), color);
}


void Drawer::DrawFiguresFromFIle()
{
	auto data = FileManager::ReadInput();
	int count;
	int rand;
	auto data_to_save = vector<string>();

	for (auto v : data)
	{
		

		if (v[0] == "TRIANGLE:") count = 3;
		if (v[0] == "RECTANGLE:") count = 2;
		if (v[0] == "CIRCLE:") count = 1;

		auto point_vec = vector<Point>();
		for (int i = 0; i < count; i++)
		{
			auto coord = v[i + 1].substr(v[i + 1].find('=') + 1);
			auto temp = MyExtensions::Split(coord, ',');
			point_vec.push_back(Point(stoi(temp[0]), stoi(temp[1])));
		}


		if (count == 1)
		{
			auto rad = MyExtensions::Split(v[2].substr(v[2].find('=') + 1), ';');

			CircleDecorator* circle = new CircleDecorator(new CircleShape());
			circle->SetPosition(Vector2f(point_vec[0].x, point_vec[0].y));
			circle->SetFillColor(Color(0, 0, 255, 100));
			circle->SetRadius(stoi(rad[0]));
			circle->Draw(*_window);


			data_to_save.push_back("Circle: Perimeter = " +
				to_string(circle->Perimeter()) +
				+" Area = " + to_string(circle->Area()));

			continue;
		}

		if (count == 2)
		{
			RectangleDecorator* rectangle = new RectangleDecorator(new RectangleShape());
			rectangle->SetPosition(Vector2f(point_vec[0].x, point_vec[0].y));
			rectangle->SetSize(Vector2f(point_vec[0].y, point_vec[1].x));
			rectangle->SetFillColor(Color(120, 255, 0, 100));
			rectangle->Draw(*_window);

			data_to_save.push_back("Rectangle: Perimeter = " +
				to_string(rectangle->Perimeter()) +
				+" Area = " + to_string(rectangle->Area()));

			continue;

		}

		if (count == 3)
		{

			TriangleDecorator* triangle = new TriangleDecorator(new ConvexShape());
			triangle->SetPointCount(3);
			triangle->SetPoint(0, Vector2f(point_vec[0].x, point_vec[0].y));
			triangle->SetPoint(1, Vector2f(point_vec[1].x, point_vec[1].y));
			triangle->SetPoint(2, Vector2f(point_vec[2].x, point_vec[2].y));
			triangle->SetFillColor(Color(255, 0, 0, 100));

			data_to_save.push_back("Triangle: Perimeter = " +
				to_string(triangle->Perimeter()) +
				+" Area = " + to_string(triangle->Area()));

			triangle->Draw(*_window);
		}
	}

	FileManager::SaveData(data_to_save);
}

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

void Drawer::DrawTriangle(Point p1, Point p2, Point p3, Color color)
{
	ConvexShape triangle(3);

	triangle.setPoint(0, Vector2f(p1.x, p1.y));
	triangle.setPoint(1, Vector2f(p2.x, p2.y));
	triangle.setPoint(2, Vector2f(p3.x, p3.y));

	triangle.setFillColor(color);
	triangle.setOutlineColor(Color(0, 0, 0));
	triangle.setOutlineThickness(2);

	_window->draw(triangle);
}

void Drawer::DrawTriangle(Triangle triangle, Color color)
{
	if (abs(triangle.Area()) <= 0.000000001)
		throw exception("Вырожденный треугольник");
	DrawTriangle(triangle.p1, triangle.p2, triangle.p3, color);
}

void Drawer::DrawRectangle(Point p1, Point p2, Color color)
{

	/*ConvexShape rectangle(4);
	rectangle.setPoint(0, Vector2f(p1.x, p1.y));
	rectangle.setPoint(1, Vector2f(p2.x, p1.y));
	rectangle.setPoint(2, Vector2f(p2.x, p2.y));
	rectangle.setPoint(3, Vector2f(p1.x, p2.y));*/

	auto rectangle =  RectangleShape(Vector2f(p2.x - p1.x, p2.y - p1.y));

	rectangle.setFillColor(color);
	rectangle.setOutlineColor(Color(0, 0, 0));
	rectangle.setOutlineThickness(2);
	rectangle.setPosition(p1.x, p1.y);
	_window->draw(rectangle);

}

void Drawer::DrawRectangle(Rectangle rectangle, Color color)
{
	
	DrawRectangle(rectangle.p1, rectangle.p3, color);
}

void Drawer::DrawCircle(Point origin, int radius, Color color)
{

	CircleShape circle(radius, 1000U);
	circle.setPosition(Vector2f(origin.x - radius, origin.y - radius));
	circle.setFillColor(color);
	circle.setOutlineColor(Color(0, 0, 0));
	circle.setOutlineThickness(2);
	_window->draw(circle);

}

void Drawer::DrawCircle(Circle circle, Color color)
{
	DrawCircle(circle.p, circle.radius, color);
}

void Drawer::DrawFiguresFromFIle()
{
	auto data = FileManager::ReadInput();
	int count;
	int rand;
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
			auto circle = Circle(point_vec[0], stoi(rad[0]));


			DrawCircle(circle, Color(0, 0, 255, 100));
			continue;
		}

		if (count == 2)
		{
			auto rectangle = Rectangle(point_vec[0], point_vec[1]);
			DrawRectangle(rectangle, Color(120, 255, 0, 100));
			continue;

		}

		if (count == 3) // todo: not working
		{
			auto triangle = Triangle(point_vec[0], point_vec[1], point_vec[2]);
			DrawTriangle(triangle, Color(255, 0, 0, 100));
		}

	}
}

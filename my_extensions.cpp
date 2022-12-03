#include "my_extensions.h"

#include <ctime>
#include <iterator>
#include <vector>

vector<string> MyExtensions::Split(string str, char delimiter)
{
	auto count = 0U;
	for (auto ch : str)
		if (ch == delimiter) count++;

	auto vec = vector<string>();
	string temp = "";

	int i = 0;
	for (size_t k = 0U; k <= count; k++)
	{
		for (i; i < str.length(); i++)
		{
			if (str[i] == delimiter) break;
			temp += str[i];
		}
		if (temp != "")
			vec.push_back(temp);
		temp.clear();
		i++;
	}




	return vec;
}

int MyExtensions::Random(int a, int b)
{
	srand(time(NULL));
	if (a > 0) return a + rand() % (b - a);
	return a + rand() % (abs(a) + b);
}

vector<Figure*> MyExtensions::CopyFigures(vector<Figure*> figures)
{
	auto vec = vector<Figure*>();
	for (auto figure : figures)
	{
		if (figure->GetType() == "Circle")
		{
			auto circle = ((CircleDecorator*)figure);
			vec.push_back(new CircleDecorator(circle));
		}
		else if (figure->GetType() == "Rectangle")
		{
			auto rect = ((RectangleDecorator*)figure);
			vec.push_back(new RectangleDecorator(rect));
		}
		else if (figure->GetType() == "Triangle")
		{
			auto triag = ((TriangleDecorator*)figure);
			vec.push_back(new TriangleDecorator(triag));
		}
		else if (figure->GetType() == "Grouped")
		{
			auto grouped = ((GroupedFigure*)figure);
			vec.push_back(new GroupedFigure(grouped));
		}
	}

	return vec;
}


//
//template <typename Out>
//void split(const std::string& s, char delim, Out result)
//{
//	std::istringstream iss(s);
//	std::string item;
//	while (getline(iss, item, delim))
//	{
//		*result++ = item;
//	}
//}

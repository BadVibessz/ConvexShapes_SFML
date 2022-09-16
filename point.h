#pragma once
class Point
{
public:
	int x, y;

	Point(int x, int y);
	Point();

	double length(Point other);

};


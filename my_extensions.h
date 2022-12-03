#pragma once
#include <string>
#include <vector>
#include "figure.h"
#include "circle_decorator.h"
#include "rectangle_decorator.h"
#include "triangle_decorator.h"
#include "grouped_figure.h"


using namespace std;
class MyExtensions
{
public:
	static vector<string> Split(string str, char delimiter);
	static int Random(int a, int b);
	static vector<Figure*> CopyFigures(vector<Figure*> figures);
	
      
};


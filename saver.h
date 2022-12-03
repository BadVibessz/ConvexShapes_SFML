#pragma once
#include "figure.h"
#include <string>
#include <vector>
#include "rectangle_decorator.h"
#include "triangle_decorator.h"
#include "circle_decorator.h"
#include "grouped_figure.h"
#include "file_manager.h"


using namespace std;
class Saver // strategy
{
protected:
	string SerializeFigureToString(Figure* figure);
	virtual string SerializeFigure(Figure* figure) = 0;

public:
	virtual void Save(string filename, vector<Figure*> figures) = 0;


};


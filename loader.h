#pragma once
#include <string>
#include <vector>
#include "figure.h"
#include <fstream>
#include "my_extensions.h"
#include "rectangle_factory.h"
#include "triangle_factory.h"
#include "circle_factory.h"
#include "grouped_figure.h"
#include <sstream>
#include "application_facade.h"

#include "circle_builder.h"
#include "grouped_figure_builder.h"
#include "rectangle_builder.h"
#include "triangle_builder.h"


using namespace std;
class Loader // template method
{
protected:
	virtual vector<Figure*> ReadFile(string filename) = 0;
	virtual void RestoreState(vector<Figure*> figures);

	vector<Figure*> ReadFiguresFromString(string str);
private:
	Figure* ReadFigureFromString(string str);
	GroupedFigure* ReadGroupedFromString(string str);

public:
	void Load(string filename);


};


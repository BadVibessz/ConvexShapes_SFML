#pragma once
#include "vector"
#include "figure.h"

using namespace std;

class AppMemento
{
private:
	vector<Figure*> _figures;

public:
	AppMemento(vector<Figure*> figures);
	vector<Figure*> GetFigures();


};


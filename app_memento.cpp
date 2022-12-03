#include "app_memento.h"
#include "circle_decorator.h"
#include "rectangle_decorator.h"
#include "triangle_decorator.h"

AppMemento::AppMemento(vector<Figure*> figures)
{
	this->_figures = vector<Figure*>(figures);
}

vector<Figure*> AppMemento::GetFigures()
{
	//return vector<Figure*>(_figures);
	return _figures;
}
#include "app_memento.h"

AppMemento::AppMemento(vector<Figure*> figures)
{
	this->_figures =figures;
}

vector<Figure*> AppMemento::GetFigures()
{
	return vector<Figure*>(_figures);
}

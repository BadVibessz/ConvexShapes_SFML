#include "txt_saver.h"

TxtSaver* TxtSaver::_instance = nullptr;


TxtSaver* TxtSaver::GetInstance()
{
	if (_instance == nullptr)
		_instance = new TxtSaver();
	return _instance;
}

string TxtSaver::SerializeFigure(Figure* figure)
{
	return SerializeFigureToString(figure);
}

void TxtSaver::Save(string filename, vector<Figure*> figures)
{
	vector<string> serializedFigures = vector<string>();

	for (auto figure : figures)
		serializedFigures.push_back(SerializeFigure(figure));

	FileManager::SaveData(serializedFigures, filename + ".txt");
}

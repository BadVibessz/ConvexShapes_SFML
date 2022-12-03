#include "binary_saver.h"

BinarySaver* BinarySaver::_instance = nullptr;

string BinarySaver::SerializeFigure(Figure* figure)
{
	return SerializeFigureToString(figure);
}

BinarySaver* BinarySaver::GetInstance()
{
	if (_instance == nullptr)
		_instance = new BinarySaver();
	return _instance;
}

void BinarySaver::Save(string filename, vector<Figure*> figures)
{
	ofstream output(filename + ".bin", ios::out | ios::binary);
	for (auto figure : figures)
	{
		string str = SerializeFigure(figure);
		output << (str + '\n').c_str();

		/*int size = str.size();
		output.write(reinterpret_cast<char*>(&size), sizeof(int));
		output.write(str.c_str(), size);*/
	}
	output.close();
}

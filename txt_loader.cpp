#include "txt_loader.h"

TxtLoader* TxtLoader::_instance = nullptr;


TxtLoader* TxtLoader::GetInstance()
{
	if (_instance == nullptr)
		_instance = new  TxtLoader();
	return _instance;
}

vector<Figure*> TxtLoader::ReadFile(string filename)
{
	ifstream input;
	input.open(filename);

	string buffer = "";
	string line;
	if (input.is_open())
		while (getline(input, line))
			buffer.append(line + '\n');

	return ReadFiguresFromString(buffer);
}


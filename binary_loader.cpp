#include "binary_loader.h"
#include <iostream>

BinaryLoader* BinaryLoader::_instance = nullptr;

BinaryLoader* BinaryLoader::GetInstance()
{
	if (_instance == nullptr)
		_instance = new BinaryLoader();
	return _instance;
}

vector<Figure*> BinaryLoader::ReadFile(string filename)
{
	ifstream input(filename, ifstream::binary);

	string buffer = "";
	char temp[1];
	while (input.read(temp, 1))
		buffer += temp[0];
	input.close();

	/*auto vec_buf = vector< uint8_t>();
	if (input.good())
	{
		std::vector<uint8_t> v_buf((std::istreambuf_iterator<char>(input)),
			(std::istreambuf_iterator<char>()));
		vec_buf = v_buf;
		input.close();
	}*/

	return ReadFiguresFromString(buffer);
}


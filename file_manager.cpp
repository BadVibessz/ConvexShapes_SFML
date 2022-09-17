#include "file_manager.h"
#include "my_extensions.h"
#include <iostream>

#include "triangle_decorator.h"

vector<vector<string>> FileManager::ReadInput()
{

	ifstream input;
	input.open(path_to_input);

	auto vec = vector<vector<string>>();

	if (input.is_open())
	{
		string line;

		while (getline(input, line))
			if (line[0] != ';')
				vec.push_back(MyExtensions::Split(line, ' '));
	}
	return vec;
}

void FileManager::SaveData(vector<string> data)
{
	ofstream output;
	output.open(path_to_output);

	for (auto str : data)
		output << str << endl;
}

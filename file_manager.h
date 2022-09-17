#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "figure.h"

using namespace std;

static  const string path_to_input = "input.txt";
static const string path_to_output = "output.txt";

class FileManager
{
public:
	static vector<vector<string>> ReadInput();
	static void SaveData(vector<string> data);
};

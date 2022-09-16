#include "my_extensions.h"

#include <ctime>
#include <iterator>
#include <vector>

vector<string> MyExtensions::Split(string str, char delimiter)
{
	auto count = 0U;
	for (auto ch : str)
		if (ch == delimiter) count++;

	auto vec = vector<string>();
	string temp = "";

	int i = 0;
	for (size_t k = 0U; k <= count; k++)
	{
		for (i; i < str.length(); i++)
		{
			if (str[i] == delimiter) break;
			temp += str[i];
		}
		if (temp != "")
			vec.push_back(temp);
		temp.clear();
		i++;
	}




	return vec;
}

int MyExtensions::Random(int a, int b)
{
	srand(time(NULL));
	if (a > 0) return a + rand() % (b - a);
	return a + rand() % (abs(a) + b);
}

//
//template <typename Out>
//void split(const std::string& s, char delim, Out result)
//{
//	std::istringstream iss(s);
//	std::string item;
//	while (getline(iss, item, delim))
//	{
//		*result++ = item;
//	}
//}

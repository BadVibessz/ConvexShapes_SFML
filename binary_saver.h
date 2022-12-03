#pragma once
#include "saver.h"
#include <fstream>
#include <sstream>
#include <string>

class BinarySaver : public Saver // singleton
{
private:
	static BinarySaver* _instance;
	BinarySaver() = default;

protected:
	string SerializeFigure(Figure * figure) override;
public:
	static BinarySaver* GetInstance();
	void Save(string filename, vector<Figure*> figures) override;

};


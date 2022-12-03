#pragma once
#include "saver.h"

class TxtSaver : public Saver // singleton
{
private:
	static TxtSaver* _instance;
	TxtSaver() = default;

protected:
	string SerializeFigure(Figure* figure) override;
public:
	static TxtSaver* GetInstance();
	void Save(string filename, vector<Figure*> figures) override;

};


#pragma once
#include "loader.h"

class BinaryLoader : public Loader // singleton
{
public:
	static BinaryLoader* GetInstance();
	vector<Figure*> ReadFile(string filename) override;

private:
	static BinaryLoader* _instance;
	BinaryLoader() = default;
};


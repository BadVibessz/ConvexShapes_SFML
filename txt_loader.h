#pragma once
#include "loader.h"


class TxtLoader : public Loader // singleton
{
public:
	static TxtLoader* GetInstance();
	vector<Figure*> ReadFile(string filename) override;

private:
	static TxtLoader* _instance;
	TxtLoader() = default;


};


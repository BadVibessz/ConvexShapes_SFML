#pragma once
#include "command.h"
#include "loader.h"

class LoadCommand : public Command
{
	Loader* _loader;
	string _filename;

public:
	string GetName() override;

	LoadCommand(Loader* loader, string filename);
	void Execute() override;

};


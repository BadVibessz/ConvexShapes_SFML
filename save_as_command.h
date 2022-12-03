#pragma once
#include "command.h"
#include "application_facade.h"
#include "saver.h"

class SaveAsCommand: public Command
{
private:
	Saver* _saver;
	string _filename;
	ApplicationFacade* _app = ApplicationFacade::GetInstance(nullptr); // nullptr because _app already exists

public:
	string GetName() override;

	SaveAsCommand(Saver* saver, string filename);
	void Execute() override;


};


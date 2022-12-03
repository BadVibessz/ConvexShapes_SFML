#pragma once
#include "command.h"
#include "application_facade.h"

class DeleteCommand : public Command
{

private:
	ApplicationFacade* _app = ApplicationFacade::GetInstance(nullptr); // nullptr because _app already exists
	vector<Figure*> _figures;

public:
	string GetName() override;
	DeleteCommand(vector<Figure*> figures);
	void Execute() override;

};


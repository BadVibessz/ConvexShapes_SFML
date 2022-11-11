#pragma once
#include "command.h"
#include "application_facade.h"

class UndoCommand : public Command
{
private:
	ApplicationFacade* _app = ApplicationFacade::GetInstance(nullptr); // nullptr because _app already exists
public:
	string GetName() override;

	UndoCommand() = default;
	void Execute() override;


};


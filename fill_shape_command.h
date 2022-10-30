#pragma once
#include "command.h"

class FillShapeCommand : public Command
{
private:
	UserHandler* _user;
public:
	string GetName() override;

	FillShapeCommand(UserHandler* user);
	void Execute() override;
};


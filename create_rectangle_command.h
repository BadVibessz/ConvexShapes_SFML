#pragma once
#include "command.h"

class CreateRectangleCommand : public Command
{
private:
	UserHandler* _user;

public:
	string GetName() override;
	CreateRectangleCommand(UserHandler* user);
	void Execute() override;

};


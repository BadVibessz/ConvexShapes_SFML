#pragma once
#include "command.h"

class CreateTriangleCommand : public Command
{
private:
	UserHandler* _user;

public:
	string GetName() override;
	CreateTriangleCommand(UserHandler* user);
	void Execute() override;

};


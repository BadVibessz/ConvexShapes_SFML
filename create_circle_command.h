#pragma once
#include "command.h"

class CreateCircleCommand : public Command
{

private:
	UserHandler* _user;

public:
	string GetName() override;
	CreateCircleCommand(UserHandler* user);
	void Execute() override;

};


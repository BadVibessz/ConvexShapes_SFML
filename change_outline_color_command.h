#pragma once
#include "command.h"

class Command;

class ChangeOutlineColorCommand : public Command
{
private:
	UserHandler* _user;

public:
	string GetName() override;
	ChangeOutlineColorCommand(UserHandler* user);
	void Execute() override;

};


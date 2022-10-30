#pragma once
#include "command.h"

class ChangeOutlineWidthCommand : public Command
{

private:
	UserHandler* _user;

public:
	string GetName() override;
	ChangeOutlineWidthCommand(UserHandler* user);
	void Execute() override;

};


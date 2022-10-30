#pragma once
#include "command.h"

class SetOutlineColorCommand : public Command
{
private:
	UserHandler* _user;
	Color _outlineColor;

public:
	string GetName() override;

	SetOutlineColorCommand(UserHandler* user, Color color);
	void Execute() override;
};


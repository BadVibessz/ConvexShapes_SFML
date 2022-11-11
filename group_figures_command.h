#pragma once
#include "command.h"

class GroupFiguresCommand : public Command
{
private:
	UserHandler* _user;
public:
	string GetName() override;

	GroupFiguresCommand(UserHandler* user);
	void Execute() override;

};


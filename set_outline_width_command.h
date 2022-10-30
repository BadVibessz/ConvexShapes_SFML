#pragma once
#include "command.h"

class SetOutlineWidthCommand : public Command
{
private:
	UserHandler* _user;
	float _thickness;

public:
	string GetName() override;

	SetOutlineWidthCommand(UserHandler* user, float thickness);
	void Execute() override;

};


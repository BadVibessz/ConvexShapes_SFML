#pragma once
#include "command.h"

class SetFillColorCommand : public Command
{

private:
	UserHandler* _user;
	Color _fillColor;
public:
	string GetName() override;
	SetFillColorCommand(UserHandler* user, Color fillColor);
	void Execute() override;

};


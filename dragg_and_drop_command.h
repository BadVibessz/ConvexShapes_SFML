#pragma once
#include "command.h"

class DraggAndDropCommand : public Command
{
private:
	UserHandler* _user;
public:
	string GetName() override;
	DraggAndDropCommand(UserHandler* user);
	void Execute() override;

};


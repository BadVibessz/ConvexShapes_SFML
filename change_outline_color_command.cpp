#include "change_outline_color_command.h"

string ChangeOutlineColorCommand::GetName()
{
	return "ChangeOutlineColorCommand";
}

ChangeOutlineColorCommand::ChangeOutlineColorCommand(UserHandler* user)
{
	this->_user = user;
}

void ChangeOutlineColorCommand::Execute()
{
	this->_user->ChangeOutlineColor();
}

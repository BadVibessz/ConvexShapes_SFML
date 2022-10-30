#include "set_outline_width_command.h"

string SetOutlineWidthCommand::GetName()
{
	return "SetOutlineWidthCommand";
}

SetOutlineWidthCommand::SetOutlineWidthCommand(UserHandler* user, float thickness)
{
	this->_user = user;
	this->_thickness = thickness;
}

void SetOutlineWidthCommand::Execute()
{
	this->_user->SetOutlineWidth(_thickness);
}

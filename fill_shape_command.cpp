#include "fill_shape_command.h"

string FillShapeCommand::GetName()
{
	return "FillShapeCommand";
}

FillShapeCommand::FillShapeCommand(UserHandler* user)
{
	this->_user = user;
}

void FillShapeCommand::Execute()
{
	this->_user->Fill();
}

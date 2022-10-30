#include "create_rectangle_command.h"

string CreateRectangleCommand::GetName()
{
	return "CreateRectangleCommand";
}

CreateRectangleCommand::CreateRectangleCommand(UserHandler* user)
{
	this->_user = user;
}

void CreateRectangleCommand::Execute()
{
	this->_user->CreateRectangle();
}

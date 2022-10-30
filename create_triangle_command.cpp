#include "create_triangle_command.h"

string CreateTriangleCommand::GetName()
{
	return "CreateTriangleCommand";
}

CreateTriangleCommand::CreateTriangleCommand(UserHandler* user)
{
	this->_user = user;
}

void CreateTriangleCommand::Execute()
{
	this->_user->CreateTriangle();
}

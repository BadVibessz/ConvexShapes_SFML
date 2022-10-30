#include "create_circle_command.h"

string CreateCircleCommand::GetName()
{
    return "CreateCircleCommand";
}

CreateCircleCommand::CreateCircleCommand(UserHandler* user)
{
    this->_user = user;
}

void CreateCircleCommand::Execute()
{
    this->_user->CreateCircle();
}

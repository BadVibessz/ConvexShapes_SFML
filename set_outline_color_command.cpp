#include "set_outline_color_command.h"

string SetOutlineColorCommand::GetName()
{
    return "SetOutlineColorCommand";
}

SetOutlineColorCommand::SetOutlineColorCommand(UserHandler* user, Color color)
{
    this->_user = user;
    this->_outlineColor = color;
}

void SetOutlineColorCommand::Execute()
{
    this->_user->SetOutlineColor(_outlineColor);
}

#include "set_fill_color_command.h"

string SetFillColorCommand::GetName()
{
    return "SetFillColorCommand";
}

SetFillColorCommand::SetFillColorCommand(UserHandler* user, Color fillColor)
{
    this->_user = user;
    this->_fillColor = fillColor;
}

void SetFillColorCommand::Execute()
{
    this->_user->SetFillingColor(this->_fillColor);
}

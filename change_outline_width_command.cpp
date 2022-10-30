#include "change_outline_width_command.h"

string ChangeOutlineWidthCommand::GetName()
{
    return "ChangeOutlineWidthCommand";
}

ChangeOutlineWidthCommand::ChangeOutlineWidthCommand(UserHandler* user)
{
    this->_user = user;
}

void ChangeOutlineWidthCommand::Execute()
{
    this->_user->ChangeOutlineWitdh();
}

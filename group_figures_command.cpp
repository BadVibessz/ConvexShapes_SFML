#include "group_figures_command.h"

string GroupFiguresCommand::GetName()
{
    return "GroupFiguresCommand";
}

GroupFiguresCommand::GroupFiguresCommand(UserHandler* user)
{
    this->_user = user;
}

void GroupFiguresCommand::Execute()
{
}

#include "delete_command.h"

string DeleteCommand::GetName()
{
    return "DeleteCommand";
}

DeleteCommand::DeleteCommand(vector<Figure*> figures)
{
    this->_figures = figures;
}

void DeleteCommand::Execute()
{
    _app->DeleteFigures(_figures);
}

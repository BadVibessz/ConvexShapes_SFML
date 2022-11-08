#include "undo_command.h"

string UndoCommand::GetName()
{
    return "UndoCommand";
}

void UndoCommand::Execute()
{
    _app->Undo();
}



#include "dragg_and_drop_command.h"

string DraggAndDropCommand::GetName()
{
	return "DraggAndDropCommand";
}

DraggAndDropCommand::DraggAndDropCommand(UserHandler* user)
{
	this->_user = user;
}

void DraggAndDropCommand::Execute()
{
	this->_user->DragAndDrop();
}

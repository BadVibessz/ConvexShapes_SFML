#include "save_as_command.h"

string SaveAsCommand::GetName()
{
    return "SaveAsCommand";
}

SaveAsCommand::SaveAsCommand(Saver* saver, string filename)
{
    this->_saver = saver;
    this->_filename = filename;

}

void SaveAsCommand::Execute()
{
    _app->SaveAs(_saver, _filename);
}

#include "load_command.h"

string LoadCommand::GetName()
{
    return "LoadCommand";
}

LoadCommand::LoadCommand(Loader* loader, string filename)
{
    this->_loader = loader;
    this->_filename = filename;
}

void LoadCommand::Execute()
{
    _loader->Load(_filename);
}

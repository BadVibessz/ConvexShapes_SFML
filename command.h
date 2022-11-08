#pragma once
#include "user_handler.h"
#include "application_facade.h"

using namespace std;
class Command
{
public:
	virtual string GetName() = 0;
	virtual void Execute() = 0;
};


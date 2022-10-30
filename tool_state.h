#pragma once
#include "user_handler.h"

class UserHandler;

using namespace std;
class ToolState
{
public:
	virtual string GetName() = 0;
	virtual void Dragging(UserHandler* user) = 0;
	virtual void FillingShape(UserHandler* user) = 0;
	virtual void ChangingOutlineColor(UserHandler* user) = 0;
	virtual void ChangingOutlineWidth(UserHandler* user) = 0;
	virtual void CreatingRectangle(UserHandler* user) = 0;
	virtual void CreatingTriangle(UserHandler* user) = 0;
	virtual void CreatingCircle(UserHandler* user) = 0;



};


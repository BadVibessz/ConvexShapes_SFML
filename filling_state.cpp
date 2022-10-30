#include "filling_state.h"

string FillingState::GetName()
{
	return "FillingState";
}

void FillingState::Dragging(UserHandler* user)
{
	user->ChangeState(new DraggingState());
}

void FillingState::FillingShape(UserHandler* user)
{
	user->ChangeState(new DraggingState());
}

void FillingState::ChangingOutlineColor(UserHandler* user)
{
	user->ChangeState(new ChangingOutlineColorState());
}

void FillingState::ChangingOutlineWidth(UserHandler* user)
{
	user->ChangeState(new ChangingOutlineWidthState());
}

void FillingState::CreatingRectangle(UserHandler* user)
{
	user->ChangeState(new CreatingRectangleState());
}

void FillingState::CreatingTriangle(UserHandler* user)
{
	user->ChangeState(new CreatingTriangleState());
}

void FillingState::CreatingCircle(UserHandler* user)
{
	user->ChangeState(new CreatingCircleState());
}

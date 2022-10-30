#include "dragging_state.h"

string DraggingState::GetName()
{
	return "DraggingState";
}

void DraggingState::Dragging(UserHandler* user)
{
	//we are in base state
}

void DraggingState::FillingShape(UserHandler* user)
{
	user->ChangeState(new FillingState());
}

void DraggingState::ChangingOutlineColor(UserHandler* user)
{
	user->ChangeState(new ChangingOutlineColorState());
}

void DraggingState::ChangingOutlineWidth(UserHandler* user)
{
	user->ChangeState(new ChangingOutlineWidthState());
}

void DraggingState::CreatingRectangle(UserHandler* user)
{
	user->ChangeState(new CreatingRectangleState());

}

void DraggingState::CreatingTriangle(UserHandler* user)
{
	user->ChangeState(new CreatingTriangleState());
}

void DraggingState::CreatingCircle(UserHandler* user)
{
	user->ChangeState(new CreatingCircleState());

}

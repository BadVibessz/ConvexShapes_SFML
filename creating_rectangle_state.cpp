#include "creating_rectangle_state.h"

string CreatingRectangleState::GetName()
{
	return "CreatingRectangleState";
}

void CreatingRectangleState::Dragging(UserHandler* user)
{
	user->ChangeState(new DraggingState());
}

void CreatingRectangleState::FillingShape(UserHandler* user)
{
	user->ChangeState(new FillingState());
}

void CreatingRectangleState::ChangingOutlineColor(UserHandler* user)
{
	user->ChangeState(new ChangingOutlineColorState());

}

void CreatingRectangleState::ChangingOutlineWidth(UserHandler* user)
{
	user->ChangeState(new ChangingOutlineWidthState());

}

void CreatingRectangleState::CreatingRectangle(UserHandler* user)
{
	user->ChangeState(new DraggingState());

}

void CreatingRectangleState::CreatingTriangle(UserHandler* user)
{
	user->ChangeState(new CreatingTriangleState());
}

void CreatingRectangleState::CreatingCircle(UserHandler* user)
{
	user->ChangeState(new CreatingCircleState());

}

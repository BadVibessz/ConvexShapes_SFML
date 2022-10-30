#include "setting_outline_width_state.h"

string ChangingOutlineWidthState::GetName()
{
	return "ChangingOutlineWidthState";
}

void ChangingOutlineWidthState::Dragging(UserHandler* user)
{
	user->ChangeState(new DraggingState());
}

void ChangingOutlineWidthState::FillingShape(UserHandler* user)
{
	user->ChangeState(new FillingState());
}

void ChangingOutlineWidthState::ChangingOutlineColor(UserHandler* user)
{
	user->ChangeState(new ChangingOutlineColorState());
}

void ChangingOutlineWidthState::ChangingOutlineWidth(UserHandler* user)
{
	user->ChangeState(new DraggingState());
}

void ChangingOutlineWidthState::CreatingRectangle(UserHandler* user)
{
	user->ChangeState(new CreatingRectangleState());
}

void ChangingOutlineWidthState::CreatingTriangle(UserHandler* user)
{
	user->ChangeState(new CreatingTriangleState());
}

void ChangingOutlineWidthState::CreatingCircle(UserHandler* user)
{

	user->ChangeState(new CreatingCircleState());
}

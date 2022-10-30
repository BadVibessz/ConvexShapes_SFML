#include "changing_outline_color_state.h"

string ChangingOutlineColorState::GetName()
{
	return "ChangingOutlineColorState";
}

void ChangingOutlineColorState::Dragging(UserHandler* user)
{
	user->ChangeState(new DraggingState());
}

void ChangingOutlineColorState::FillingShape(UserHandler* user)
{
	user->ChangeState(new FillingState());
}

void ChangingOutlineColorState::ChangingOutlineColor(UserHandler* user)
{
	user->ChangeState(new DraggingState());
}

void ChangingOutlineColorState::ChangingOutlineWidth(UserHandler* user)
{
	user->ChangeState(new ChangingOutlineWidthState());
}

void ChangingOutlineColorState::CreatingRectangle(UserHandler* user)
{
	user->ChangeState(new CreatingRectangleState());

}

void ChangingOutlineColorState::CreatingTriangle(UserHandler* user)
{
	user->ChangeState(new CreatingTriangleState());
}

void ChangingOutlineColorState::CreatingCircle(UserHandler* user)
{
	user->ChangeState(new CreatingCircleState());
}

#include "creating_circle_state.h"

string CreatingCircleState::GetName()
{
    return "CreatingCircleState";
}

void CreatingCircleState::Dragging(UserHandler* user)
{
    user->ChangeState(new DraggingState());
}

void CreatingCircleState::FillingShape(UserHandler* user)
{
    user->ChangeState(new FillingState());
}

void CreatingCircleState::ChangingOutlineColor(UserHandler* user)
{
    user->ChangeState(new ChangingOutlineColorState());
}

void CreatingCircleState::ChangingOutlineWidth(UserHandler* user)
{
    user->ChangeState(new ChangingOutlineWidthState());
}

void CreatingCircleState::CreatingRectangle(UserHandler* user)
{
    user->ChangeState(new CreatingRectangleState());
}

void CreatingCircleState::CreatingTriangle(UserHandler* user)
{
    user->ChangeState(new CreatingTriangleState());
}

void CreatingCircleState::CreatingCircle(UserHandler* user)
{
    user->ChangeState(new DraggingState());

}

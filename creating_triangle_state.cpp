#include "creating_triangle_state.h"

string CreatingTriangleState::GetName()
{
    return "CreatingTriangleState";
}

void CreatingTriangleState::Dragging(UserHandler* user)
{
    user->ChangeState(new DraggingState());
}

void CreatingTriangleState::FillingShape(UserHandler* user)
{
    user->ChangeState(new FillingState());

}

void CreatingTriangleState::ChangingOutlineColor(UserHandler* user)
{
    user->ChangeState(new ChangingOutlineColorState());

}

void CreatingTriangleState::ChangingOutlineWidth(UserHandler* user)
{
    user->ChangeState(new ChangingOutlineWidthState());

}

void CreatingTriangleState::CreatingRectangle(UserHandler* user)
{
    user->ChangeState(new CreatingRectangleState());

}

void CreatingTriangleState::CreatingTriangle(UserHandler* user)
{
    user->ChangeState(new DraggingState());

}

void CreatingTriangleState::CreatingCircle(UserHandler* user)
{
    user->ChangeState(new CreatingCircleState());

}

#pragma once
#include "tool_state.h"

#include "user_handler.h"
#include "dragging_state.h"
#include "filling_state.h"
#include "setting_outline_width_state.h"
#include "creating_triangle_state.h"
#include "creating_circle_state.h"


class CreatingRectangleState : public ToolState
{
public:
	string GetName() override;
	void Dragging(UserHandler* user) override; // to dragg
	void FillingShape(UserHandler* user) override; // to fill shape
	void ChangingOutlineColor(UserHandler* user) override; // to change outline color
	void ChangingOutlineWidth(UserHandler* user) override; // to change outline thickness
	void CreatingRectangle(UserHandler* user) override; // to dragg
	void CreatingTriangle(UserHandler* user) override; // to create triag
	void CreatingCircle(UserHandler* user) override; // to create circle



};


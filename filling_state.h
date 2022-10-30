#pragma once

#include "user_handler.h"
#include "dragging_state.h"
#include "setting_outline_width_state.h"
#include "changing_outline_color_state.h"
#include "creating_rectangle_state.h"
#include "creating_triangle_state.h"
#include "creating_circle_state.h"




class FillingState : public ToolState
{
public:
	string GetName() override;
	void Dragging(UserHandler* user) override; // to dragg
	void FillingShape(UserHandler* user) override; // to dragg (base state)
	void ChangingOutlineColor(UserHandler* user) override; // to change outline color
	void ChangingOutlineWidth(UserHandler* user) override; // to set outline color
	void CreatingRectangle(UserHandler* user) override; // to create rect
	void CreatingTriangle(UserHandler* user) override; // to create triag
	void CreatingCircle(UserHandler* user) override; // to create circle


};


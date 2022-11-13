#include "application_facade.h"

int main()
{
	const int window_width = 900;
	const int window_height = 900;

	auto app = ApplicationFacade::GetInstance(window_width, window_height);
	app->Run();
}
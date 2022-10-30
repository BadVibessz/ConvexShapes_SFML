#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
#include <SFML/Graphics.hpp>
#include "my_extensions.h"
#include "drawer.h"
#include "file_manager.h"
#include "event_handler.h"
#include "application_facade.h"



using namespace sf;

int main()
{
	const int window_width = 900;
	const int window_height = 900;

	RenderWindow window(VideoMode(window_width, window_height), "SFML works!");
	window.setFramerateLimit(60);

	ContextSettings settings;
	settings.antialiasingLevel = 8;

	auto app = ApplicationFacade::GetInstance(&window);

	app->ReadInput();
	app->SaveData();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
			app->HandleEvent(event);

		app->DrawInput();
	}
}
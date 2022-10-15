#include <iostream>
#include <SFML/Graphics.hpp>
#include "my_extensions.h"
#include "drawer.h"
#include "file_manager.h"
#include "event_handler.h"

using namespace sf;

int main()
{
	const int window_width = 900;
	const int window_height = 900;

	RenderWindow window(VideoMode(window_width, window_height), "SFML works!");
	window.setFramerateLimit(60); // without this line cpu and gpu usage shoots up


	Drawer drawer = Drawer(&window);

	ContextSettings settings;
	settings.antialiasingLevel = 8;



	auto figures = FileManager::ReadInput();
	FileManager::SaveData(figures);

	EventHandler::SetWindow(&window);
	EventHandler::SetShapes(figures);



	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			else
				EventHandler::HandleEvent(event, drawer);
		}

		window.clear(Color(255, 255, 255));
		drawer.DrawAxis(Color(0, 0, 0));
		drawer.DrawFigures(figures);

		window.display();
	}
}
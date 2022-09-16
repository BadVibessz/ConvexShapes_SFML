#include <iostream>
#include <SFML/Graphics.hpp>
#include "my_extensions.h"

#include "drawer.h"
#include "file_manager.h"

using namespace sf;

int main()
{
	const int window_width = 900;
	const int window_height = 900;

	RenderWindow window(VideoMode(window_width, window_height), "SFML works!");

	/*View view; //todo: move origin to center of the screen
	view.move(window_width / 2, window_height / 2);
	view.setCenter(window_width / 2, window_height / 2);
	view.setSize(window_width, window_height);
	window.setView(view);*/

	Drawer drawer = Drawer(&window, window_width, window_width);

	ContextSettings settings;
	settings.antialiasingLevel = 8;


	auto manager = FileManager();
	

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color(255, 255, 255));
		drawer.DrawAxis(Color(0, 0, 0));

		auto vec = manager.ReadInput();

		drawer.DrawFiguresFromFIle();

		/*ConvexShape triangle(3);
		triangle.setPoint(0, Vector2f(0, 0));
		triangle.setPoint(1, Vector2f(100, 0));
		triangle.setPoint(2, Vector2f(100, 100));

		triangle.setFillColor(Color(0,0,255));

		window.draw(triangle);*/
		window.display();
	}
}
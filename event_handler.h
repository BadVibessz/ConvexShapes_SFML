#include <SFML/Graphics.hpp>
#include <vector>
#include "figure.h"
#include "grouped_figure.h"
#include "drawer.h"


using namespace sf;
using namespace std;

class EventHandler
{
private:
	static vector<Figure*> _figures;
	static RenderWindow* _window;
	static bool _is_multi_select;
	static bool _is_moving;
	static Figure* _selected_figure;
	static float _dx, _dy;

public:
	static void SetShapes(vector <Figure*> figures);
	static void HandleEvent(Event e, Drawer drawer);
	static void SetWindow(RenderWindow* window);

};

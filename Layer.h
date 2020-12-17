#pragma once

#include "Tile.h"

class Layer
{
	public:
		Layer(void);
		~Layer(void);

		void loadContent();
		void unloadContent();
		void update();
		void draw(ALLEGRO_DISPLAY* DISPLAY);
};


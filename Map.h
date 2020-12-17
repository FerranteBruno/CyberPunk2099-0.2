#pragma once

#include "Layer.h"

class Map
{
	public:
		Map(void);
		~Map(void);

		void loadContent();
		void unloadContent();
		void update();
		void draw(ALLEGRO_DISPLAY* DISPLAY);
};


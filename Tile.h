#pragma once

#include "allegro5/allegro.h"
#include <iostream>

class Tile
{
public:

	Tile(void);
	~Tile(void);

	static enum State{ SOLIDO, PASIVO};

	void setContent(ALLEGRO_BITMAP * tileImg, State state, std::pair<float, float> posicion);
	void unloadContent();
	void update();
	void draw(ALLEGRO_DISPLAY * DISPLAY);


};


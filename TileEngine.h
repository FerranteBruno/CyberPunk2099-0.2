#include <stdio.h>
#include <stdlib.h>
#include "iostream"
#include "allegro5/allegro5.h"

class tileEngine
{
	private:
		int tilewidth = 32;
		int tileheight = 32;
		int width = 32, height = 32;
		int columnas = 40, filas = 22;
		int mapSizeX = 40, mapSizeY = 22;
		ALLEGRO_BITMAP* fondo = al_load_bitmap("IMG/Arena.bmp");
		

	public:
		float getMap() { return **map; };
		float **map;
		float **loadMap();
		void dibujarMapa(float **map);

};
#include "TileEngine.h"
#include <iostream>

float** tileEngine::loadMap()
{

	FILE* p;

	fopen_s(&p,"IMG/capoide.csv", "r");

	map = (float**)malloc((filas) * sizeof(float*));
	for (int i = 0; i < filas; i++) {
		map[i] = (float*)malloc((columnas) * sizeof(float));
	}

	for (int i = 0; i < columnas; i++) {

		for (int j = 0; j < filas; j++) {

			fscanf_s(p, "%d,", &map[i][j]);
		}
	}
	fclose(p);
	return map;
}

void tileEngine::dibujarMapa(float **map)
{
	int i=0, j=0;
	float sy = 0;
	float sx = 0;
	

	for (i = 0; i < columnas; i++) {
		std::cout << map[i][j];
		sx = map[i][j];
		
		for (j = 0; j < filas; j++) {
			sy = map[i][j];
		}
	}
	al_draw_bitmap_region(fondo, 0, 0, tilewidth, tileheight, sy, sx, NULL);
}

#include "TileEngine.h"
#include <iostream>

float **tileEngine::loadMap()
{

	FILE* p;


	fopen_s(&p,"IMG/capoide.csv", "r");

	map = (float**)malloc((filas) * sizeof(float*));
	for (int i = 0; i < filas; i++) {
		map[i] = (float*)malloc((columnas) * sizeof(float*));
	}

	for (int i = 0; i < filas; i++) {

		for (int j = 0; j < columnas; j++) {

			fscanf_s(p, "%d", map[i][j], NULL);
		}
	}
	fclose(p);
	return map;
}

void tileEngine::dibujarMapa(float **map)
{
	int i, j;

	

	for (i = 0; i < columnas; i++) {
		float sy = *map[i];
		
		for (j = 0; j < filas; j++) {
			float sx = *map[j];
			al_draw_bitmap_region(fondo, 0, 0, tilewidth, tileheight, sy, sx, NULL);
		}
	}

}

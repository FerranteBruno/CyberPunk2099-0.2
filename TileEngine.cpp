#include "TileEngine.h"
#include <iostream>

int** tileEngine::loadMap()
{

	FILE* p;

	fopen_s(&p,"IMG/capoide.csv", "r");



	map = (int**)malloc((columnas) * sizeof(int*));
	for (int j = 0; j < columnas; j++) {
		map[j] = (int*)malloc((filas) * sizeof(int));
	}

	for (int i = 0; i < columnas; i++) {

		for (int j = 0; j < filas; j++) {

			fscanf_s(p, "%d,", &map[i][j]);
		}
	}
	fclose(p);
	return map;
}

void tileEngine::dibujarMapa(int**map)
{
	int i=0, j=0;
	float sy = 0;
	float sx = 0;
	

	for (i = 0; i < columnas; i++) {
		//std::cout << map[i][j];
		sx = map[i][j];
		
		for (j = 0; j < filas; j++) {
			sy = map[i][j];
			//std::cout << map[i][j];
		}
	}
	al_draw_bitmap_region(fondo, sx, sy, tilewidth, tileheight, sx + width, sy + height, NULL);
	
}

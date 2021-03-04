#pragma once
#include <stdio.h>
#include <string.h>

struct structPuntuacion {
	char SKN[3];
	int secElapsed;
	int minElapsed;
	int puntos;
};

structPuntuacion prasePuntuacion(char* _SKN, int _puntos, int _secElapsed, int _minElapsed);
bool leerDeDisco(int pos, bool& leyo);
structPuntuacion leerDeDisco(int pos);
int cantidadDePuntuaciones();
void grabarPuntuacion(structPuntuacion score);
void top5Score(/*char* _SKN[3], int _puntos, int _secElapsed, int _minElapsed*/);
//void top52();

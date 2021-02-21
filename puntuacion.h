#pragma once
#include"inGame.h"


class puntuacion : public inGame
{

private:

	ALLEGRO_FONT* score;
	int x = 100, y = 50;
	char SKN[3];
	int puntos;
	int secElapsed;
	int minElapsed;


public:
	//game engine
	void cmd();
	void update();
	void drawn();
	//getters
	char getSKN() { return SKN[3]; };/// TODO: a revisar
	int getPuntos() {return puntos;};
	int getSecElapsed() { return secElapsed; };
	int getMinElapsed() { return minElapsed; };
	//setters
	void setSKN(char _skn[3]) { for (int i = 0; i < 3; i++){ SKN[i] = _skn[i]; } };
	void setPuntos(int _puntos) { puntos = _puntos; };
	void setSecElapsed(int _secElapsed) { secElapsed = _secElapsed; };
	void setMinElapsed(int _minElapsed) { minElapsed = _minElapsed; };
	//methods
	puntuacion();
	int acumular();
	void mostrar();
	void ver_podio();
	void pintascore();
	~puntuacion();

};



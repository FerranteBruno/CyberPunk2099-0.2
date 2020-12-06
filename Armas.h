#pragma once
#include "allegro5/allegro.h"
#include "jugador.h"

enum ESTADOS_ARMAS { DOWN1, UP1, LEFT1, RIGHT1, ATACANDO1, QUIETO1 };

class Armas
{
	private:
		ALLEGRO_BITMAP* armas;
		int x, y;
		int direccion;
		float dirA;
		int dmg;
		ESTADOS_ARMAS _estados;
	public:
		void cmd(jugador jugador, int sx, int sy);
		void update();
		void draw(int sx, int sy, int x, int y);
		void pinta(int sourseX, int sourceY, int x, int y);
		void setx(int _x) { x = _x; };
		void sety(int _y) { y = _y; };
		ALLEGRO_BITMAP* getBitmap() { return armas; };
		void inicia(int _x, int _y);
		~Armas();
};


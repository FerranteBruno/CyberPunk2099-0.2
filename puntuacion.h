#pragma once
#include"inGame.h"


class puntuacion : public inGame
{

	private : 
		
		ALLEGRO_FONT* score;
		int x=100, y=50;
		int puntos;


	public : 
		puntuacion();
		int acumular();
		void mostrar();
		void ver_podio();
		void pintascore();
		~puntuacion();

};



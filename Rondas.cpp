#include "Rondas.h"
#include <iostream>
#include <sstream>

Rondas::Rondas()
{
	fuente = al_load_font("IMG/BROADW.ttf", 16, NULL);
	cont = 0;
	rondas = 1;
	controlDeRondas = ESPERA;
	comienza = false;
	finaliza = false;
	pausado = false;
	//min = 0;
	//sec = 0;
	//_min = 0;
	//_seg = 0;
}

Rondas::~Rondas()
{
}

void Rondas::cmd(ALLEGRO_TIMER* timer, jugador jugador, bool& estanVivos, bool daaale)
{

	comienza = daaale;
	if (rondas == 1) {
		///RONDA 1:
		if (!(jugador.ha_muerto()) && estanVivos == true && comienza == false && finaliza == false && pausado==false) {
			controlDeRondas = ESPERA;
			
		}

		if (!(jugador.ha_muerto()) && pausado == true) {
			controlDeRondas = PAUSA;
			
		}

		if (!(jugador.ha_muerto()) && estanVivos == true && comienza == true && pausado==false) {
			controlDeRondas = COMIENZA;
			
		}

		if (!jugador.ha_muerto() && estanVivos == false && finaliza == true && comienza == false) {
			controlDeRondas = FINALIZA;
			std::cout << "hola";
			rondas++;
		}
	}

	///RONDA 2:
	else if (rondas == 2) {

		if (!(jugador.ha_muerto()) && estanVivos == true && comienza == false && finaliza == false && pausado == false) {
			controlDeRondas = ESPERA;

		}

		if (!(jugador.ha_muerto()) && pausado == true) {
			controlDeRondas = PAUSA;

		}

		if (!(jugador.ha_muerto()) && estanVivos == true && comienza == true && pausado == false) {
			controlDeRondas = COMIENZA;

		}

		if (!jugador.ha_muerto() && estanVivos == false && finaliza == true && comienza == false) {
			controlDeRondas = FINALIZA;
			std::cout << "hola";
			rondas++;
		}
	}

	///RONDA 3:
	else if (rondas == 3) {

		if (!(jugador.ha_muerto()) && estanVivos == true && comienza == false && finaliza == false && pausado == false) {
			controlDeRondas = ESPERA;

		}

		if (!(jugador.ha_muerto()) && pausado == true) {
			controlDeRondas = PAUSA;

		}

		if (!(jugador.ha_muerto()) && estanVivos == true && comienza == true && pausado == false) {
			controlDeRondas = COMIENZA;

		}

		if (!jugador.ha_muerto() && estanVivos == false && finaliza == true && comienza == false) {
			controlDeRondas = FINALIZA;

			rondas++;
		}
	}
}

void Rondas::update(ALLEGRO_TIMER* timer)
{
	switch (controlDeRondas) {

	case ESPERA:

		break;

	case PAUSA:
		al_stop_timer(timer);
		//al_rest(60);

		break;

	case COMIENZA:

		al_start_timer(timer);

		if (al_get_timer_count(timer) == 30) {
			sec++;
		
			al_set_timer_count(timer, 0);
		}

		if (sec == 60) {
			min++;
		}

		if (min == 1 && sec == 0) {
			controlDeRondas = FINALIZA;
		}

		break;

	case FINALIZA:
		al_rest(10);
		//al_stop_timer(timer);

		break;

	}
}

void Rondas::draw(jugador &jugador, bool estanVivos)
{	
	if (controlDeRondas == ESPERA) {
		al_draw_text(fuente, al_map_rgb(255, 0, 0), 640, 60, ALLEGRO_ALIGN_CENTER, "Presione F1 para comenzar la ronda");
	}

	else if (controlDeRondas == PAUSA){
		al_draw_text(fuente, al_map_rgb(255, 0, 0), 640, 60, ALLEGRO_ALIGN_CENTER, "Juego en pausa");
	}

	else if (controlDeRondas == COMIENZA /*&& !(jugador.ha_muerto())*/) {

		//fuente = al_load_font("IMG/BROADW.ttf", 16, NULL);
		
		/*min;
		sec;*/
		al_draw_text(fuente, al_map_rgb(200, 200, 0), 640, 40, ALLEGRO_ALIGN_CENTER, "Ronda numero");
		al_draw_textf(fuente, al_map_rgb(200, 200, 0), 640, 60, ALLEGRO_ALIGN_CENTER, "%d", rondas);
		al_draw_textf(fuente, al_map_rgb(255,0,0), 625, 20, ALLEGRO_ALIGN_CENTER, "%d",min);
		al_draw_text(fuente, al_map_rgb(255, 0, 0), 640, 20, ALLEGRO_ALIGN_CENTER, _dopunto);
		al_draw_textf(fuente, al_map_rgb(255, 0, 0), 655, 20, ALLEGRO_ALIGN_CENTER, "%d" , sec);
	}

	else if (controlDeRondas == FINALIZA) {
		al_draw_text(fuente, al_map_rgb(255, 0, 0), 640, 60, ALLEGRO_ALIGN_CENTER, "Has completado la ronda! Para continuar presione F1, F2 para detener la ronda");
	}

	///al_destroy_font(fuente);
}

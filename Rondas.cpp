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

void Rondas::cmd(ALLEGRO_TIMER* timer, jugador jugador, bool& estanVivos, bool& estanVivos2, bool& estanVivos3, bool daaale)
{

	comienza = daaale;

	///RONDA 1:
	if (!(jugador.ha_muerto()) && estanVivos == true && comienza == false) {
		controlDeRondas = ESPERA;
	}

	if (!(jugador.ha_muerto()) && pausado == true) {
		controlDeRondas = PAUSA;
	}

	if (!(jugador.ha_muerto()) && estanVivos == true && comienza == true) {
		controlDeRondas = COMIENZA;
	}

	if (!jugador.ha_muerto() && estanVivos == false && finaliza == true) {
		controlDeRondas = FINALIZA;
		finaliza = daaale;
		rondas++;
	}

	///RONDA 2:

	if (!(jugador.ha_muerto()) && estanVivos2 == true && comienza == false && rondas == 2) {
		controlDeRondas = ESPERA;
	}

	if (!(jugador.ha_muerto()) && pausado == true && rondas == 2) {
		controlDeRondas = PAUSA;
	}

	if (!(jugador.ha_muerto()) && estanVivos2 == true && rondas == 2 && comienza == true) {
		controlDeRondas = COMIENZA;
	}

	if (!jugador.ha_muerto() && estanVivos2 == false && finaliza == true && rondas == 2) {
		controlDeRondas = FINALIZA;
		rondas++;
	}
}

void Rondas::update(ALLEGRO_TIMER* timer)
{
	switch (controlDeRondas) {

	case ESPERA:

		break;

	case PAUSA:

		al_rest(60);

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

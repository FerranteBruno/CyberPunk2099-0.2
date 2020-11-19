#include "Rondas.h"
#include <iostream>
#include <sstream>

Rondas::Rondas()
{
}

Rondas::~Rondas()
{
}

void Rondas::cmd(ALLEGRO_TIMER* timer, bool estanVivos, jugador jugador)
{
	if (!(jugador.ha_muerto()) && estanVivos == true && comienza == false) {
		controlDeRondas = ESPERA;
	}

	if (!(jugador.ha_muerto()) && pausado == true) {
		controlDeRondas = COMIENZA;
	}

	if (!(jugador.ha_muerto()) && estanVivos == true && comienza == true) {
		controlDeRondas = COMIENZA;
	}

	if (!jugador.ha_muerto() && estanVivos == true && finaliza == true) {
		controlDeRondas = FINALIZA;
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
	if (controlDeRondas == COMIENZA /*&& !(jugador.ha_muerto())*/) {

		fuente = al_load_font("IMG/BROADW.ttf", 16, NULL);
		
		min;
		sec;

		al_draw_textf(fuente, al_map_rgb(255,0,0), 625, 20, ALLEGRO_ALIGN_CENTER, "%d",min);
		al_draw_text(fuente, al_map_rgb(255, 0, 0), 640, 20, ALLEGRO_ALIGN_CENTER, _dopunto);
		al_draw_textf(fuente, al_map_rgb(255, 0, 0), 655, 20, ALLEGRO_ALIGN_CENTER, "%d" , sec);
	}

	al_destroy_font(fuente);
}

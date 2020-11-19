#include "Rondas.h"

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
	switch (controlDeRondas){
		
	case ESPERA:
		break;

	case PAUSA:
		al_rest(60);
		break;

	case COMIENZA:

		break;

	case FINALIZA:

		break;

	}


}

void Rondas::draw()
{	
	

}

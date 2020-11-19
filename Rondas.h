#pragma once
#include "allegro5/allegro5.h"
#include "jugador.h"

enum ESTADORONDAS{ESPERA, PAUSA, COMIENZA, FINALIZA};

class Rondas
{
private:
	int cont;
	int rondas;
	int controlDeRondas;
	bool comienza;
	bool finaliza;
	bool pausado;
	ESTADORONDAS estaditto;
public:
	Rondas();
	~Rondas();
	void cmd(ALLEGRO_TIMER* timer, bool estanVivos, jugador jugador);
	void update(ALLEGRO_TIMER* timer);
	void draw();
	void setComienza(bool _comienza) { comienza = _comienza; };
	void setFinaliza(bool _finaliza) { finaliza = _finaliza; };
	void setPausado(bool _pausado) { pausado = _pausado; };
	bool getComienza(bool _comienza) { return comienza; };
	bool getFinaliza(bool _finaliza) { return finaliza; };
	bool getPausado(bool _pausado) { return pausado; };

};
#pragma once
#include "allegro5/allegro5.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "jugador.h"

enum ESTADORONDAS{ESPERA, PAUSA, COMIENZA, FINALIZA};

class Rondas
{
private:
	ALLEGRO_COLOR color = al_map_rgb(0, 0, 0);
	ALLEGRO_FONT* fuente;
	const char* _min;
	const char* _dopunto = ":";
	const char* _seg;
	int cont;
	int rondas;
	int controlDeRondas;
	bool comienza;
	bool finaliza;
	bool pausado;
	int sec;
	int min;
	ESTADORONDAS estaditto;
public:
	Rondas();
	~Rondas();
	void cmd(ALLEGRO_TIMER* timer, jugador jugador, bool& estanVivos, bool daaale);
	void update(ALLEGRO_TIMER* timer);
	void draw(jugador &jugador , bool estanVivos);
	void setComienza(bool _comienza) { comienza = _comienza; };
	void setFinaliza(bool _finaliza) { finaliza = _finaliza; };
	void setPausado(bool _pausado) { pausado = _pausado; };
	bool getComienza() { return comienza; };
	bool getFinaliza() { return finaliza; };
	bool getPausado() { return pausado; };
	int getNumRonda() { return rondas; };
	void setNumRonda(int x) { rondas = x; }

};
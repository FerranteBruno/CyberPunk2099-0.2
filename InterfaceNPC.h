#pragma once
#include "allegro5/allegro5.h"
#include "jugador.h"

class InterfaceNPC
{
public:
	virtual void cmd(jugador& jugador, bool cerca, bool start) = 0;
	virtual void draw(int sx, int sy, int) = 0;
	virtual void update(ALLEGRO_TIMER* npcTimer) = 0;
	virtual bool ha_muerto() = 0;
	virtual float getx() = 0;
	virtual float gety() = 0;
	virtual void inicia() = 0;
	virtual bool atacando() = 0;
	virtual int getAtaca() = 0;
	virtual void setDir(float _x) = 0;
	virtual void sufre_daño(int dmg, InterfaceNPC& guardia) = 0;
	virtual void posiciona(float _x, float _y) = 0;
	virtual void setEstado(int dire) = 0;
};


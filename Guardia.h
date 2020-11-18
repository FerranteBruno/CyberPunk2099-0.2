#pragma once
#include "NPC.h"
class Guardia :
    public NPC
{
private:
    ALLEGRO_BITMAP* guardia;
    ESTADOS _estados;
    float x, y;
    int ataca;
    int vida;
    int vidaAct;
    int vidaMax;
    int def;
    bool muerto;
    float moveSpeed;
    float dir;
    int direccion;
public:
    Guardia(int _vida);
    void draw(int sx, int sy, int cont);
    void update(ALLEGRO_TIMER* npcTimer);
    void cmd(jugador& jugador, bool cerca);
    void inicia();
    void pinta2(float sx, float sy);
    void pintaVida();
    bool ha_muerto() { return muerto; };
    void setDir(float _x) { direccion = _x; };
    void sufre_daño(int dmg, InterfaceNPC& guardia);
};


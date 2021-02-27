#pragma once
#include "NPC.h"


class Esqueleto :
    public NPC
{
protected:
    ALLEGRO_BITMAP* esqueleto;
    ESTADOS _estados;
    int ataca;
    int vida;
    int vidaAct;
    int vidaMax;
    int def;
    bool muerto;
    float moveSpeed;
    float dir;
    int direccion;
    int murio;
    int dmg;
public:
    float x, y;
    float pX, pY;
    Esqueleto(int _vida);
    void draw(int sx, int sy, int cont);
    void update(ALLEGRO_TIMER* npcTimer);
    void cmd(jugador& jugador, bool cerca, bool start);
    void inicia(int _x, int _y);
    void posiciona(float _x, float _y);
    void pinta2(float sx, float sy);
    void pintaVida();
    bool ha_muerto() { return muerto; };
    void sufre_daño(int dmg, InterfaceNPC& guardia);
    bool atacando();
    float getx() { return x; };
    float gety() { return y; };
    int getAtaca() { return ataca; };
    bool getMuerto() { return muerto; };
    void setDir(float _x) { direccion = _x; };
    void setEstado(int dire) { direccion = dire; };
    void setRevive(bool revivio);
    void setNose0() { murio = 0; };
    void nose() { murio++; }
    int getMuerte() { return murio; }
    int getDmg() { return dmg; }
    FRect *npcRect;
    FRect* prevNpcRect;
    //pnutajes
    int getPuntaje() { return puntajeAEntregar; };
};


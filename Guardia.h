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
};


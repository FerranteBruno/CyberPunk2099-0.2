#pragma once
#include "allegro5/allegro.h"
#include "jugador.h"
#include "allegro5/allegro_primitives.h"
// Esta clase se encarga del manejo del jugador

enum ESTADOS { DOWN, UP, LEFT, RIGHT, ATACANDO , QUIETO};

class NPC {
private:
    ALLEGRO_BITMAP* npc;
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
    float getDir() { return dir; };
    void pintaVida();
    void cmd(jugador &jugador, bool cerca);
    void update();
    void draw(int sx, int sy, int);
    NPC(int _vida);
    void inicia();
    void pinta2(float, float);
    int getVida() { return vida; };
    int getVidaAct() { return vidaAct; };
    float getx() { return x; };
    float gety() { return y; };
    void setx(float _x) { x = _x; };
    void sety(float _y) { y = _y; };
    ALLEGRO_BITMAP* getBitmap() { return npc; };
    void posiciona(float _x, float _y);
    bool atacando() ;
    void no_ataca() { ataca = -3; };
    void sufre_daño(int dmg, NPC &guardia);
    bool ha_muerto() { return muerto; };
    
    //void IA(jugador &jugador);
    ~NPC();
};
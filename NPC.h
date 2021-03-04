#pragma once
#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include "InterfaceNPC.h"
// Esta clase se encarga del manejo del jugador

enum ESTADOS { DOWN, UP, LEFT, RIGHT, ATACANDO , QUIETO};

class NPC : public InterfaceNPC {
protected:
    ALLEGRO_BITMAP* npc;
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
    int dmg;
    int murio;
    int puntajeAEntregar;
    /*float x, y;
    float pX, pY;*/
public:
    float x, y;
    float pX, pY;
    ALLEGRO_SAMPLE* camina;
    ALLEGRO_SAMPLE* atak;
    float getDir() { return dir; };
    void pintaVida();
    virtual void cmd(jugador &jugador, bool cerca, bool start);
    virtual void update(ALLEGRO_TIMER* npcTimer);
    virtual void draw(int sx, int sy, int);
    NPC();
    void inicia(int _x, int _y);
    void pinta2(float, float);
    int getVida() { return vida; };
    int getVidaAct() { return vidaAct; };
    int getAtaca() { return ataca; };
    
    float getx() { return x; };
    float gety() { return y; };
    bool getMuerto() { return muerto; };
    void setx(float _x) { x = _x; };
    virtual void setDir(int _x) { direccion = _x; };
    void sety(float _y) { y = _y; };
    void setEstado(int dire) { direccion = dire; };
    ALLEGRO_BITMAP* getBitmap() { return npc; };
    void posiciona(float _x, float _y);
    bool atacando() ;
    void no_ataca() { ataca = -3; };
    void sufre_dano(int dmg, NPC &guardia);
    void setReviveNPC(bool revivio);
    void setNose0() { murio = 0; };
    virtual bool ha_muerto() { return muerto; };
    virtual int getDmg() { return dmg; }
    //void IA(jugador &jugador);
    FRect *npcRect;
    FRect *prevNpcRect;
    //pnutajes
    int getPuntaje() { return puntajeAEntregar; };
    ~NPC();
};
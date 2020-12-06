#pragma once
#include "allegro5/allegro.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
//#include "Armas.h"


// Esta clase se encarga del manejo del jugador
class jugador {
private:
    ALLEGRO_BITMAP* p1;
    ALLEGRO_SAMPLE* atak;
    ALLEGRO_SAMPLE* camina;
    ALLEGRO_SAMPLE* camina2;
    ALLEGRO_FONT* lavida;
    float x, y;
    /*int direccion;
    int animacion;*/
    int ataca=0;
    int vida;
    int vidaMax;
    int mana;
    int aguante;
    int defBase;
    float moveSpeed;
    float ddir;
    bool muerto=false;
    bool empezarRonda = false;
public:
    void inicia();
    void pinta(int, int);
    void teclado(/*Armas arma1,*/ ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events,
    bool done, float &sourceX, float &sourceY, float&dir, bool draw, bool active, int moveSpeed, ALLEGRO_TIMER* Timer, ALLEGRO_TIMER* frameTimer);
    float getx() { return x; };
    float gety() { return y; };    
    int getAtk() { return ataca; };
    float getSpeed() { return moveSpeed; };
    float getDir() { return ddir; };
    int getVida() { return vida; };
    int getVidaMax() { return vidaMax; };
    bool getEmpezarRonda() { return empezarRonda; };
    void setEmpezarRonda(bool _rondaEmpieza) { empezarRonda = _rondaEmpieza; };
    void setAtk(int Atk) { ataca = Atk; };
    void setx(float _x) { x = _x; };
    void sety(float _y) { y = _y; };
    void setpx(float _x) { x += _x; };
    void setmx(float _x) { x -= _x; };
    void setpy(float _y) { y += _y; };
    void setmy(float _y) { y -= _y; };
    void setSpeed(float _moveSpeed) { moveSpeed = _moveSpeed; };
    void setpSpeed(float _moveSpeed) { moveSpeed += _moveSpeed; };
    void setmSpeed(float _moveSpeed) { moveSpeed -= _moveSpeed; };
    void setDir(float dir) { ddir = dir; };
    void pintaVida();
    ALLEGRO_BITMAP* getBitmap() { return p1; };
    void posiciona(float _x, float _y);
    bool atacando() { return ataca > 1; };
    void sufre_daño(int dmg, jugador& jugador);
    bool ha_muerto() { if (muerto)return true; };
    jugador();
    ~jugador();
    //void no_ataca() { ataca = -3; };
};




#include "Centinela.h"
#include "inGame.h"
#include <iostream>
#include <time.h>

Centinela::Centinela(int _vida)
{

    vida = _vida;
    vidaMax = _vida;
    vidaAct = vida;
    moveSpeed = 2;
    murio = 0;
    dmg = 1;
    puntajeAEntregar = 350;

}


void Centinela::cmd(jugador& jugador, bool cerca, bool start)
{
    if (start == true && !(jugador.ha_muerto())) {
        if (!cerca) {
            if ((jugador.getx() - x) > 0) direccion = RIGHT;
            if ((jugador.getx() - x) < 0) direccion = LEFT;
            if ((jugador.gety() - y) > 0) direccion = DOWN;
            if ((jugador.gety() - y) < 0) direccion = UP;
        }
        else {

            //cout << "Estoy atacando " << endl;
            direccion = ATACANDO;

        }
    }
    else {
        direccion = QUIETO;
    }
    /*if (direccion == QUIETO) {
        direccion = ATACANDO;
    }*/

    

}


void Centinela::update(ALLEGRO_TIMER* npcTimer)
{
    pY = y;
    pX = x;
    switch (direccion) {
    case RIGHT:
        x += moveSpeed;

        break;
    case LEFT:
        x -= moveSpeed;

        break;
    case UP:
        y -= moveSpeed;

        break;
    case DOWN:
        y += moveSpeed;

        break;
    case QUIETO:
        y += 0;
        x += 0;
        //no_ataca();
        break;
    case ATACANDO:
        if (al_get_timer_count(npcTimer) > 10) {
            //      al_play_sample(, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);

            ataca = 1;
            al_set_timer_count(npcTimer, 0);
        }
        else {
            ataca = 0;
        }
        break;
    }
    delete npcRect;
    delete prevNpcRect;

    npcRect = new FRect(x, y, 32, 32);
    prevNpcRect = new FRect(pX, pY, 32, 32);
}

void Centinela::draw(int sx, int sy, int cont) {


    if (direccion < 4) {
        sy = direccion;
        dir = sy;
        sx += (al_get_bitmap_width(centinela) / 9) * cont;
    }
    else {
        //cout << "dir "<<  dir <<endl;
        sy = dir;
    }
    //cout << "sx " << sx << endl;


    pinta2(sx, sy);

}

void Centinela::inicia(int _x, int _y)
{


    centinela = al_load_bitmap("IMG/centinela.bmp");


    posiciona(_x, _y);
    

    npcRect = new FRect(x, y, 32, 32);
    prevNpcRect = new FRect(pX, pY, 32, 32);

}

void Centinela::posiciona(float _x, float _y) {
    x = _x;
    y = _y;
    
}


void Centinela::pinta2(float sx, float sy) {
    al_convert_mask_to_alpha(centinela, al_map_rgb(0, 0, 0));
    al_draw_bitmap_region(centinela, sx, sy * (al_get_bitmap_height(centinela) / 4), al_get_bitmap_width(centinela) / 9, al_get_bitmap_height(centinela) / 4, x, y, NULL);
    pintaVida();
}

void Centinela::pintaVida() {

    al_draw_filled_rectangle(x, y, x + ((vidaAct * 28) / vida), y + 4, al_map_rgb(0, 255, 0));

}

void Centinela::sufre_dano(int dmg, InterfaceNPC& guardia)
{

    if (!muerto)
    {
        vidaAct -= dmg;

        if (vidaAct <= 0)
        {
            muerto = true;

        }
    }
}

bool Centinela::atacando() {
    if (direccion == ATACANDO) {
        return true;
    }
}

void Centinela::setRevive(bool revivio)
{
    muerto = !revivio;
    vidaAct = vidaMax;
}

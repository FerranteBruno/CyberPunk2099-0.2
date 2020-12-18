#include "esqueleto.h"
#include "inGame.h"
#include <iostream>
#include <time.h>

Esqueleto::Esqueleto(int _vida)
{
    vida = _vida;
    vidaMax = _vida;
    vidaAct = vida;
    moveSpeed = 2;
    murio = 0;
    dmg = 1;
    muerto = false;
}


void Esqueleto::cmd(jugador& jugador, bool cerca, bool start)
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


void Esqueleto::update(ALLEGRO_TIMER* npcTimer)
{

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
}

void Esqueleto::draw(int sx, int sy, int cont) {


    if (direccion < 4) {
        sy = direccion;
        dir = sy;
        sx += (al_get_bitmap_width(esqueleto) / 9) * cont;
    }
    else {
        //cout << "dir "<<  dir <<endl;
        sy = dir;
    }
    //cout << "sx " << sx << endl;


    pinta2(sx, sy);

}

void Esqueleto::inicia(int _x, int _y)
{


    esqueleto = al_load_bitmap("IMG/esqueletos.bmp");
    

    posiciona(_x, _y);

    
}

void Esqueleto::posiciona(float _x, float _y) {
    x = _x;
    y = _y;
}


void Esqueleto::pinta2(float sx, float sy) {
    al_convert_mask_to_alpha(esqueleto, al_map_rgb(0, 0, 0));
    al_draw_bitmap_region(esqueleto, sx, sy * (al_get_bitmap_height(esqueleto) / 4), al_get_bitmap_width(esqueleto) / 9, al_get_bitmap_height(esqueleto) / 4, x, y, NULL);
    pintaVida();
}

void Esqueleto::pintaVida() {

    al_draw_filled_rectangle(x, y, x + ((vidaAct * 28) / vida), y + 4, al_map_rgb(0, 255, 0));

}

void Esqueleto::sufre_daño(int dmg, InterfaceNPC& guardia)
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

bool Esqueleto::atacando() {
    if (direccion == ATACANDO) {
        return true;
    }
}

void Esqueleto::setRevive(bool revivio)
{
    muerto = !revivio;
    vidaAct = vidaMax;
}

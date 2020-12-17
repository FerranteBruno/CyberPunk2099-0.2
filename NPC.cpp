#include "NPC.h"
#include "inGame.h"
#include <iostream>
#include <time.h>
using namespace std;
void NPC::posiciona(float _x, float _y) {
    x = _x;
    y = _y;
}

void NPC::sufre_daño(int dmg, NPC &guardia)
{
    //muerto = false;

    if (!muerto)
    {
        vidaAct-= dmg;
        //cout << "vidita" << vidaAct << endl;
        if (vidaAct <= 0)
        {
            muerto = true;
            guardia.~NPC();
        }
    }
}

NPC::~NPC()
{
    if (muerto) {
       // al_destroy_bitmap(npc);
    }
}



void NPC::cmd(jugador &jugador, bool cerca, bool start)
{
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
    /*if (direccion == QUIETO) {
        direccion = ATACANDO;
    }*/
   
}

void NPC::update(ALLEGRO_TIMER* npcTimer)
{
    
    switch (direccion) {
    case RIGHT:
        x+= moveSpeed;
        
        break;
    case LEFT:
        x-= moveSpeed;
        
        break;
    case UP:
        y-= moveSpeed;
        
        break;
    case DOWN:
        y+= moveSpeed;
        
        break;
    case QUIETO:
        y += 0;
        x += 0;
        no_ataca();
        break;
    case ATACANDO:
        if (al_get_timer_count(npcTimer) > 10) {
            al_play_sample(atak, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
            ataca = 1;
            al_set_timer_count(npcTimer, 0);
        }
        else {
            ataca = 0;
        }
        break;
    }
}

void NPC::draw(int sx, int sy, int cont) {
    
    
    if (direccion < 4) {
        sy = direccion;
        dir = sy;
        sx += (al_get_bitmap_width(npc) / 8) * cont;
    }
    else {
        //cout << "dir "<<  dir <<endl;
        sy = dir;
    }
    //cout << "sx " << sx << endl;
    
    
    pinta2(sx,sy);
    
}

NPC::NPC()
{
    vida = 100;
    vidaMax = 100;
    vidaAct = 100;
    moveSpeed = 1;
    //cout << "esta es la vida: " << vida << endl;
    //cout << "esta es la vida actual: " << vidaAct << endl;
}

void NPC::inicia()
{
    

    npc = al_load_bitmap("IMG/4083.bmp");
    camina = al_load_sample("IMG/10.wav");
    atak = al_load_sample("IMG/2.wav");
    int rx=0, ry=0;

    rx = 1 + rand() % 1280;
    ry = 1 + rand() % 720;

    posiciona(rx, ry);

    // inicializar vbles
    //direccion = 0;
    //animacion = 0;
    /*this->x = 500;
    this->y = 500;*/
}


void NPC::pinta2(float sx, float sy) {
    al_convert_mask_to_alpha(npc, al_map_rgb(0, 0, 0));
    al_draw_bitmap_region(npc, sx, sy * (al_get_bitmap_height(npc)/4), al_get_bitmap_width(npc) / 8, al_get_bitmap_height(npc) / 4, x, y, NULL);
    pintaVida();
}

bool NPC::atacando() {
    if (direccion == ATACANDO) {
        return true;
    }
}

void NPC::pintaVida() {

    al_draw_filled_rectangle(x, y, x + ((vidaAct * 28) / vida), y + 4, al_map_rgb(0, 255, 0));

}

void NPC::setReviveNPC(bool revivio)
{
    muerto = !revivio;
    vida = vidaMax;
}
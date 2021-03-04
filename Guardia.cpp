#include "Guardia.h"

Guardia::Guardia(int _vida)
{


    vida = _vida;
    vidaMax = _vida;
    vidaAct = vida;
    moveSpeed = 1;
    murio = 0;
    dmg = 1;
    puntajeAEntregar = 120;
    //cout << "esta es la vida: " << vida << endl;
    //cout << "esta es la vida actual: " << vidaAct << endl;
}


void Guardia::cmd(jugador& jugador, bool cerca, bool start)
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


void Guardia::update(ALLEGRO_TIMER* npcTimer)
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

    delete npcRect;
    delete prevNpcRect;

    npcRect = new FRect(x, y, 32, 32);
    prevNpcRect = new FRect(pX, pY, 32, 32);
}

void Guardia::draw(int sx, int sy, int cont) {


    if (direccion < 4) {
        sy = direccion;
        dir = sy;
        sx += (al_get_bitmap_width(guardia) / 8) * cont;
    }
    else {
        //cout << "dir "<<  dir <<endl;
        sy = dir;
    }
    //cout << "sx " << sx << endl;


    pinta2(sx, sy);

}

void Guardia::inicia(int _x, int _y)
{


    guardia = al_load_bitmap("IMG/4083.bmp");
    camina = al_load_sample("IMG/10.wav");
    atak = al_load_sample("IMG/2.wav");
    /*int rx = 0, ry = 0;

    srand(time(NULL));

    rx = 1 + rand() % 2;
    ry = 1 + rand() % 2;*/

    posiciona(_x, _y);

    // inicializar vbles
    //direccion = 0;
    //animacion = 0;
    /*this->x = 500;
    this->y = 500;*/
    npcRect = new FRect(x, y, 32, 32);
    prevNpcRect = new FRect(pX, pY, 32, 32);
}

void Guardia::posiciona(float _x, float _y) {
    x = _x;
    y = _y;
    
}


void Guardia::pinta2(float sx, float sy) {
    al_convert_mask_to_alpha(guardia, al_map_rgb(0, 0, 0));
    al_draw_bitmap_region(guardia, sx, sy * (al_get_bitmap_height(guardia) / 4), al_get_bitmap_width(guardia) / 8, al_get_bitmap_height(guardia) / 4, x, y, NULL);
    pintaVida();
}

void Guardia::pintaVida() {

    al_draw_filled_rectangle(x, y, x + ((vidaAct * 28) / vida), y + 4, al_map_rgb(0, 255, 0));

}

void Guardia::sufre_dano(int dmg, InterfaceNPC& guardia)
{
    //muerto = false;

    if (!muerto)
    {
        vidaAct -= dmg;
        //cout << "vidita" << vidaAct << endl;
        if (vidaAct <= 0)
        {
            muerto = true;
            //guardia.~NPC();
        }
    }
}

bool Guardia::atacando() {
    if (direccion == ATACANDO) {
        return true;
    }
}

void Guardia::setReviveNPC(bool revivio)
{
    muerto = !revivio;
    vidaAct = vidaMax;
}

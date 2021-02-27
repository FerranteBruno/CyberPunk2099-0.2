#include "puntuacion.h"


void puntuacion::cmd(Rondas& ronda, jugador& jugador)
{
    if (ronda.getNumRonda() == 1)
    {
        if (ronda.getSec() > 0 && !jugador.ha_muerto()) {
            _pstate = DISMINUIR;
        }
    }
    if (ronda.getNumRonda() == 2)
    {
        if (ronda.getSec() > 0 && !jugador.ha_muerto()) {
            _pstate = DISMINUIR;
        }
    }
    if (ronda.getNumRonda() == 3)
    {
        if (ronda.getSec() > 0 && !jugador.ha_muerto()) {
            _pstate = DISMINUIR;

        }
    }
}



void puntuacion::update(Rondas& ronda, ALLEGRO_TIMER* timer)
{


    switch (_pstate)
    {
    case AUMENTAR:

            //puntos += puntajeTemp;
            _pstate = DISMINUIR;

        break;
    case DISMINUIR:


        if (ronda.getComienza()) {
            al_start_timer(timer);
            if (ronda.getMin() == 0 && ronda.getSec() > 0) {

                if (al_get_timer_count(timer) == 30) {
                    secElapsed++;
                    puntos -= 3;
                    al_set_timer_count(timer, 0);
                }

            }
            else if (ronda.getMin() > 0 && ronda.getSec() == 0) {

                if (al_get_timer_count(timer) == 30) {
                    minElapsed++;
                    secElapsed = 0;
                    puntos -= 30 * 3;
                    al_set_timer_count(timer, 0);
                }
            }
        }
        else {
            al_set_timer_count(timer, 0);
            al_stop_timer(timer);
        }
        break;

    case PAUSADO:
        _pstate = DISMINUIR;
        break;

    default:
        _pstate = DISMINUIR;
        break;
    }
}


void puntuacion::draw()
{
    al_draw_textf(score, al_map_rgb(640, 540, 0), 640, 540, ALLEGRO_ALIGN_CENTER, "%d", puntos);
}

puntuacion::puntuacion() {

    //seleccionamos la fuente
    score = al_load_font("IMG/BROADW.ttf", 36, 0);

    for (int i = 0; i < 3; i++) {
        *SKN[i] = x;
    }
    secElapsed = 0;
    minElapsed = 0;
    puntos=1000;
    _pstate = PAUSADO;
}

int puntuacion::acumular() {

    puntos+=10;

    return puntos;
}

void puntuacion::pintascore() {

    

    al_draw_text(score, al_map_rgb(0, 0, 0), x, y, ALLEGRO_ALIGN_LEFT, "PUNTUACION");

    al_flip_display();
    

    al_destroy_font(score);

}

void puntuacion :: mostrar() {


};

void puntuacion :: ver_podio() {
//fread , for , 3 mejores 
};

puntuacion::~puntuacion(){}

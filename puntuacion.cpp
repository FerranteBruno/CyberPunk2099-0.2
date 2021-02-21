#include "puntuacion.h"


void puntuacion::cmd()
{
}

void puntuacion::update()
{
}

void puntuacion::drawn()
{
}

puntuacion::puntuacion() {

    //seleccionamos la fuente
    score = al_load_font("IMG/BROADW.ttf", 36, 0);

    for (int i = 0; i < 3; i++) {
        SKN[i] = x;
    }
    secElapsed = 0;
    minElapsed = 0;
    puntos=0;
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

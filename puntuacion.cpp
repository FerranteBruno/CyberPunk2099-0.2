#include "puntuacion.h"


 puntuacion::puntuacion() {
 
     puntos=0000;
}

int puntuacion::acumular() {

    puntos+=10;

    return puntos;
}

void puntuacion::pintascore() {

    score = al_load_font("IMG/BROADW.ttf", 36,0);

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

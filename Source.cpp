#include <iostream>

using namespace std;
#include "allegro5/allegro.h"
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "windows.h"
#include "inGame.h"
/* Este comentario es pitoputopato*/



void inicia_allegro(){
    al_init();
    al_init_image_addon();
    al_init_primitives_addon();

    al_init_font_addon();
    al_init_ttf_addon();
    
    
    al_install_mouse();
    al_install_keyboard();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(4);
    const int PANTALLA_ANCHO = 1280;
    const int PANTALLA_ALTO = 720;
    ALLEGRO_DISPLAY* ventanita = al_create_display(PANTALLA_ANCHO, PANTALLA_ALTO);
    al_set_target_backbuffer(ventanita);
}
    
    

// programa principal
int main() {
    ///ALLEGRO_DISPLAY;
    inicia_allegro();
    inGame eljuego;

    eljuego.GAME();
    eljuego.~inGame();
    return 0;
}
 

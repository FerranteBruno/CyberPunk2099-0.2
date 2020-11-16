#include "inGame.h"
#include <iostream>
using namespace std;
/*void inGame::carga_juego(, NPC guardia, Armas arma1)
{
    ///jugador.inicia();
    //al_create_mouse_cursor("IMG/cursor.bmp", 0, 0);
    // cargamos imagenes

    /*loading = al_load_bitmap("IMG/intro.bmp");
    menu1 = al_load_bitmap("IMG/menu1.bmp");
    menu2 = al_load_bitmap("IMG/menu2.bmp");
    menu3 = al_load_bitmap("IMG/menu3.bmp");
    menu4 = al_load_bitmap("IMG/menu4.bmp");
    menu5 = al_load_bitmap("IMG/menu5.bmp");
    menu6 = al_load_bitmap("IMG/menu6.bmp");
    cursor = al_load_bitmap("IMG/cursor.bmp");


    // cargamos imagenes del primer escenario
    fondo = al_load_bitmap("IMG/Arena.bmp");

    //choque = al_load_bitmap("IMG/Arena-choque.bmp");
    //alto = al_load_bitmap("IMG/Arena-Magenta.bmp");

    

    ALLEGRO_BITMAP* p1 = jugador.getBitmap();
    ALLEGRO_BITMAP* npc = guardia.getBitmap();
    ALLEGRO_COLOR rojito = al_map_rgb(255, 0, 0);
    

    /*jugador.inicia(arma1);
    guardia.inicia();
}*/

/*void inGame::teclado(jugador jugador, int x, int y, Armas arma1, ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events,
    bool done, int& sourceX, int& sourceY, int& dir, bool draw, bool active, int moveSpeed) {

    al_wait_for_event(event_queue, &events);
    al_get_keyboard_state(&keyState);
    if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        done = true;
    }
    else if (events.type == ALLEGRO_EVENT_TIMER) {
        active = true;
        if (al_key_down(&keyState, ALLEGRO_KEY_S)) {
            //jugador.setpy(moveSpeed);
            y += moveSpeed;
            dir = 0;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_W)) {
            //jugador.setmy(moveSpeed);
            y -= moveSpeed;
            dir = 3;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_SPACE)) {
            moveSpeed = 5;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_D)) {
            //jugador.setmx(moveSpeed);
            x -= moveSpeed;
            dir = 2;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_A)) {
            //jugador.setpx(moveSpeed);
            x += moveSpeed;
            dir = 1;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_LCTRL && jugador.getAtk() == 0)) {
            jugador.setAtk(1);
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_LCTRL && jugador.getAtk() == 1)) {
            jugador.setAtk(2);
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE))
        {
            done = true;
        }
        else {
            active = false;
        }

    }
    if (active) {
        sourceX += al_get_bitmap_width(jugador.getBitmap()) / 3;
        //sourceX += al_get_bitmap_width(arma1.getBitmap()) / 6;
    }
    else {
        sourceX = 32;
    }
    if (sourceX >= al_get_bitmap_width(jugador.getBitmap())) {
        sourceX = 0;
    }
    sourceY = dir;
    draw = true;
    if (draw) {
        jugador.setx(x);
        jugador.sety(y);
        arma1.setx(jugador.getx());
        arma1.sety(jugador.gety());
    }

    return;
}*/

void inGame::actualiza_juego(jugador jugador)
{
    int ax, ay;
    ax = jugador.getx();
    ay = jugador.gety();
    

    bool choca = false;
    float px = jugador.getx();
    float py = jugador.gety();
    
}

void inGame::pinta_jugador(jugador jugador, float x, float y)
{
    jugador.pinta(x, y);
}

void inGame::pinta_fondo()
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(fondo, 0, 0, NULL);
    //al_flip_display();
}

void inGame::pinta_npc(NPC& guardia, float x, float y) {
    guardia.pinta2(x, y);
}

void inGame::pinta_arma(Armas arma1, float sourceX, float sourceY, float x, float y) {
    arma1.pinta(sourceX, sourceY, x, y);
    //arma1.draw(sourcex, sourcey, x,y);
}

//acá vamos a declarar las colisiones
bool inGame::colision(float x, float y, float npc_x, float npc_y, float width, float height, float dir, float moveSpeed) {
    
    if (x + width < npc_x || x > npc_x + width || y + height < npc_y || y > npc_y + height) {
        return false;
    }
    else
    {
    return true;
    }
}

bool inGame::cerca(float x, float y, float npc_x, float npc_y, float width, float height, float dir, float moveSpeed) {

    if ((x + width)+2 < npc_x || x > (npc_x + width)+2 || (y + height)+2 < npc_y || y > (npc_y + height)+2) {
        return false;
    }
    else
    {
        return true;
    }
}


void inGame::dmg_npc(jugador& jugador, NPC& guardia)
{
    if ((jugador.atacando() == true) && (cerca(jugador.getx(), jugador.gety(), guardia.getx(), guardia.gety(), 30, 46, jugador.getDir(), jugador.getSpeed())==true)
        && (guardia.ha_muerto()==false) /*&& (miraHacia(jugador, guardia) == true*/)
    {
        if ((miraHaciaAbajo(jugador, guardia) == true) || (miraHaciaArriba(jugador, guardia) == true) || (miraHaciaDerecha(jugador, guardia) == true) || (miraHaciaIzquierda(jugador, guardia) == true)) {
            sufreDaño = al_load_sample("IMG/10.wav");
            int xn = 2 + rand() % 2;
            //cout << "entre" << endl;
            //jugador.no_ataca();
            //sonido_espada_da();
            al_play_sample(sufreDaño, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
            guardia.sufre_daño(xn, guardia);
            //cout << "tiene :" << guardia.getVidaAct() << "de vida" << endl;
           //al_play_sample
        }

    }
}

void inGame::dmg_jugador(jugador &jugador, NPC& guardia) {

    if ((guardia.atacando() == true) && (cerca(jugador.getx(), jugador.gety(), guardia.getx(), guardia.gety(), 30, 46, jugador.getDir(), jugador.getSpeed()) == true)
        && (jugador.ha_muerto() == false) && (guardia.ha_muerto() == false))
    {

            int xn = 2 + rand() % 2;
            //cout << "entre" << endl;
            //jugador.no_ataca();
            //sonido_espada_da();
            jugador.sufre_daño(xn, jugador);

            cout << "ESTOY ACA" << jugador.getVida() << endl;
            //cout << "tiene :" << jugador.getVida() << "de vida" << endl;
        

    }
}

bool inGame::miraHaciaArriba(jugador &jugador, NPC &guardia){
    
        if ((jugador.getDir() == 0) && ((guardia.gety() +5) > jugador.gety())) return true;
        else return false; 
}

bool inGame::miraHaciaAbajo(jugador& jugador, NPC& guardia) {

    if ((jugador.getDir() == 3) && ((guardia.gety() -5) < jugador.gety())) return true;
    else return false;
}

bool inGame::miraHaciaDerecha(jugador& jugador, NPC& guardia) {

    if ((jugador.getDir() == 2) && (guardia.getx() > jugador.getx())) return true;
    else return false;
}

bool inGame::miraHaciaIzquierda(jugador& jugador, NPC& guardia) {

    if ((jugador.getDir() == 1) && (guardia.getx() < jugador.getx())) return true;
    else return false;
}

void inGame::GAME(){
    
    const float FPS = 30;
    const float frameFPS = 0.5;

    

    ///Creamos el objeto de eventos
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

    //registramos los eventos de la wea
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
    ALLEGRO_TIMER* frameTimer = al_create_timer(1.0 / FPS);
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_timer_event_source(frameTimer));
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    

    /*jugador jugador;
    NPC guardia;
    Armas arma1;
    jugador.inicia();
    guardia.inicia();
    //eljuego.carga_juego(jugador, guardia, arma1);*/

    al_start_timer(timer);
    al_start_timer(frameTimer);

    int x = 0, y = 0;

    bool done = false;
    
    ALLEGRO_EVENT events;
    ALLEGRO_KEYBOARD_STATE keyState;
    while (!done) {
        
        al_wait_for_event(event_queue, &events);
        al_get_keyboard_state(&keyState);

        if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            done = true;
        }
        else if (events.type == ALLEGRO_EVENT_MOUSE_AXES) {
            x = events.mouse.x;
            y = events.mouse.y;

        }
        else if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if (events.mouse.button & 1);
            else if (events.mouse.button & 2);
        }
        //comienza el jueguin
        menu_principal(event_queue, events, done, x, y);
    }
    
    juego_inicia(keyState, event_queue, events, timer, frameTimer);
    al_destroy_event_queue(event_queue);
    this->~inGame();
}

void inGame::menu_principal(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events, bool &done, float x, float y) {

    if (x > 970 && x < 1120 &&
        y>360 && y < 420) {
        al_clear_to_color(vacio);
        al_draw_bitmap(menu3, 0, 0, NULL);
        al_flip_display();
        if (events.mouse.button & 1) {
            done = true;
        }
    }

    else if (x > 970 && x < 1260 &&
        y>460 && y < 510) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu4, 0, 0, NULL);
        al_flip_display();
        if (events.mouse.button & 1) {

            //a = true;   //funcion jugar a desarrolar
            done = true;
        }
    }

    else if (x > 388 && x < 921 &&
        y>408 && y < 590) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu2, 0, 0, NULL);
        al_flip_display();
        if (events.mouse.button & 1) {

            //a = true;   //funcion jugar a desarrolar
            done = true;
        }
    }

    else if (x > 970 && x < 1262 &&
        y>531 && y < 594) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu5, 0, 0, NULL);
        al_flip_display();
        if (events.mouse.button & 1) {

           //a = true;   //funcion jugar a desarrolar
            done = true;
        }
    }

    else if (x > 970 && x < 1105 &&
        y>624 && y < 688) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu6, 0, 0, NULL);
        al_flip_display();
        if (events.mouse.button & 1) {

            //a = true;   //funcion jugar a desarrolar
            done = true;
        }
    }

    else {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu1, 0, 0, NULL);
        al_flip_display();
    }
    
}

void inGame::juego_inicia(ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events, ALLEGRO_TIMER* timer, ALLEGRO_TIMER* frameTimer) {
    jugador jugador;
    NPC guardia(100);
    Armas arma1;
    tileEngine pruebita;
        ;

    al_unregister_event_source(event_queue, al_get_mouse_event_source());
   // ALLEGRO_BITMAP* p1 = jugador.getBitmap();
    //ALLEGRO_BITMAP* npc = guardia.getBitmap();
    ALLEGRO_COLOR rojito = al_map_rgb(255, 0, 0);
    ALLEGRO_SAMPLE* song;
    ALLEGRO_SAMPLE_INSTANCE* midi;
    ///this->carga_juego();
    
    song = al_load_sample("IMG/1.mid");

    midi = al_create_sample_instance(song);
    al_set_sample_instance_playmode(midi, ALLEGRO_PLAYMODE_LOOP);

    al_attach_sample_instance_to_mixer(midi, al_get_default_mixer());
    

    jugador.inicia();
    float x = jugador.getx();
    float y = jugador.getx();
    arma1.inicia(x, y);
    guardia.inicia();

    bool a = false;
    bool draw = true, active = false;

    jugador.setSpeed(3);
    float sourceX = 32, sourceY = 0, dir = sourceY, dirA = sourceY;
    float sx = 0, sy = 0;
    int cont = 0;
    while (!a) {
        actualiza_juego(jugador);
        al_clear_to_color(vacio);
        pinta_fondo();
        //pruebita.dibujarMapa(pruebita.loadMap());
        pinta_npc(guardia, 0, 0);
        al_clear_to_color(vacio);
        pinta_jugador(jugador, sourceX, dir);
        al_play_sample_instance(midi);
        //pinta_arma(arma1, sourceX, dir, jugador.getx(), jugador.gety());
        
        
        bool done = false;
        while (!done)
        {
            
            //teclado(jugador,x, y, arma1, keyState, event_queue, events, done, sourceX, sourceY, dir, draw, active, jugador.getSpeed());
            //aca iría el teclado en caso de explosión de código
            //jugador.teclado(arma1, keyState, event_queue, events, done, sourceX, sourceY, dir, draw, active, jugador.getSpeed(), timer, frameTimer);
            if (draw) {
                //pruebita.dibujarMapa(pruebita.loadMap());
                pinta_fondo();
                if (!jugador.ha_muerto()) {
                    jugador.teclado(/*arma1,*/ keyState, event_queue, events, done, sourceX, sourceY, dir, draw, active, jugador.getSpeed(), timer, frameTimer);
                    pinta_jugador(jugador, sourceX, sourceY);
                    arma1.cmd(jugador, sourceX, sourceY);
                    arma1.update();
                    pinta_arma(arma1, sourceX, sourceY, jugador.getx(), jugador.gety());
                    
                }
                if (jugador.ha_muerto()) {
                    jugador.~jugador();
                    arma1.~Armas();
                }
                //pinta_jugador(jugador, sourceX, sourceY);
                dmg_npc(jugador,guardia);
                dmg_jugador(jugador, guardia);
                //pruebita.loadMap();
                //cout << guardia.getVidaAct() << endl;
                
                if (colision(jugador.getx(), jugador.gety(), guardia.getx(), guardia.gety(), 30, 46, dir, jugador.getSpeed()) && !(guardia.ha_muerto() ) ){
                    if (dir == 0) jugador.setmy(jugador.getSpeed());
                    else if (dir == 1) jugador.setpx(jugador.getSpeed());
                    else if (dir == 2) jugador.setmx(jugador.getSpeed());
                    else if (dir == 3) jugador.setpy(jugador.getSpeed());
                        //cout << guardia.getVida() << endl;
                }
                if (!(guardia.ha_muerto())) {
                    if (cont == 8) cont = 0;
                    guardia.cmd(jugador, cerca(jugador.getx(), jugador.gety(), guardia.getx(), guardia.gety(), 30, 46, dir, jugador.getSpeed()));
                    guardia.update();
                    //pinta_npc(guardia, 0, 0);
                    //cout << sy;
                    guardia.draw(sx, sy, cont);
                    cont++;
                    //dmg_npc(jugador, guardia);
                }
                else {
                    guardia.~NPC();
                }
                //pinta_arma(arma1, sourceX, sourceY, jugador.getx(), jugador.gety());
                al_flip_display();
            }
        }
    }
}

inGame::~inGame() {
}
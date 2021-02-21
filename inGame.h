#pragma once
#include "NPC.h"
#include "jugador.h"
#include "Armas.h"
#include "TileEngine.h"
#include"Esqueleto.h"
#include "Guardia.h"
#include "Rondas.h"
#include"Centinela.h"

/*#ifndef INGAME_H_INCLUDED
#define INGAME_H_INCLUDED*/
//#include "allegro5/allegro.h"
//ALLEGRO_BITMAP* choque;
//ALLEGRO_BITMAP* alto;

class inGame {
    private:
        
        ALLEGRO_BITMAP* loading = al_load_bitmap("IMG/intro.bmp");
        ALLEGRO_BITMAP* menu1 = al_load_bitmap("IMG/menu1.bmp");
        ALLEGRO_BITMAP* menu2 = al_load_bitmap("IMG/menu2.bmp");
        ALLEGRO_BITMAP* menu3 = al_load_bitmap("IMG/menu3.bmp");
        ALLEGRO_BITMAP* menu4 = al_load_bitmap("IMG/menu4.bmp");
        ALLEGRO_BITMAP* menu5 = al_load_bitmap("IMG/menu5.bmp");
        ALLEGRO_BITMAP* menu6 = al_load_bitmap("IMG/menu6.bmp");
        ALLEGRO_BITMAP* cursor = al_load_bitmap("IMG/cursor.bmp");
        ALLEGRO_BITMAP* sonido1 = al_load_bitmap("IMG/sonido1.bmp");
        ALLEGRO_BITMAP* sonido2 = al_load_bitmap("IMG/sonido2.bmp");
        ALLEGRO_BITMAP* sonido3 = al_load_bitmap("IMG/sonido3.bmp");
        ALLEGRO_BITMAP* sonnido4 = al_load_bitmap("IMG/sonido4.bmp");
        ALLEGRO_BITMAP* opciones1 = al_load_bitmap("IMG/opciones1.bmp");
        ALLEGRO_BITMAP* opciones2 = al_load_bitmap("IMG/opciones2.bmp");
        ALLEGRO_BITMAP* opciones3 = al_load_bitmap("IMG/opciones3.bmp");
        ALLEGRO_BITMAP* opciones4 = al_load_bitmap("IMG/opciones4.bmp");
        ALLEGRO_BITMAP* controles1 = al_load_bitmap("IMG/controles1.bmp");
        ALLEGRO_BITMAP* controles2 = al_load_bitmap("IMG/controles.bmp");
        ALLEGRO_COLOR vacio = al_map_rgb(0, 0, 0);
        ALLEGRO_SAMPLE* sufreDaño;
        ALLEGRO_SAMPLE* sufreDaño2;

    public:
        void GAME();
        int encima, debajo, izquierda, derecha;
        ALLEGRO_BITMAP* fondo = al_load_bitmap("IMG/Arena.bmp");
        ALLEGRO_COLOR rojito = al_map_rgb(255, 0, 0);
        //Metodos de pintura
        void pinta_fondo();
        void pinta_jugador(jugador jugador, float x, float y);
        void pinta_npc(NPC &guardia, float x, float y);
        void pinta_esqueleto(Esqueleto &esqueleto,float x,float y);
        void pinta_arma(Armas arma1, float sourceX, float sourceY, float x, float y);
        //Metodos de gameplay
        void actualiza_juego(jugador jugador);
        void juego_inicia(ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events, ALLEGRO_TIMER* timer, ALLEGRO_TIMER* frameTimer, ALLEGRO_TIMER* npcTimer, ALLEGRO_TIMER* rondasTimer);
        void menu_principal(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events, bool &done, float x, float y);
        bool colision(float x, float y, float npc_x, float npc_y, float width, float height);
        bool rect(jugador& jugador, FRect* npcRect, NPC& elnpc);
        bool guardRect(Guardia& npc, FRect* npcRect, NPC& elnpc);
        bool centiRect(Centinela& npc, FRect* npcRect, NPC& elnpc);
        bool esqueRect(Esqueleto& npc, FRect* npcRect, NPC& elnpc);
        bool cerca(float x, float y, float npc_x, float npc_y, float width, float height, float dir, float moveSpeed);
        void dmg_npc(jugador& jugador, InterfaceNPC &guardia);
        void dmg_jugador(jugador& jugador, InterfaceNPC &guardia);
        void dmg_esqueleto(jugador& jugador, InterfaceNPC& guardia);
        bool miraHaciaArriba(jugador &jugador, InterfaceNPC& guardia);
        bool miraHaciaAbajo(jugador& jugador, InterfaceNPC& guardia);
        bool miraHaciaIzquierda(jugador& jugador, InterfaceNPC& guardia );
        bool miraHaciaDerecha(jugador& jugador, InterfaceNPC& guardia );
        void menu_opciones(ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events, bool& done, float x, float y);
        void checkRondas(ALLEGRO_TIMER* timer, Rondas &rondita, jugador& jugador, bool estanVivos, bool estanVivos2, bool estanVivos3);
        void updateRondas(ALLEGRO_TIMER* timer, Rondas &rondita, jugador &jugador);
        void drawRondas(ALLEGRO_TIMER* timer, Rondas &rondita, jugador &jugador, bool estanVivos);
        bool Daño(jugador& jugador);
        int suma_puntos(bool daño);
        ~inGame();
};

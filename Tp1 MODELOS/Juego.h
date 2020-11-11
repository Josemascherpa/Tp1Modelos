#ifndef JUEGO_H
#define JUEGO_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>
#include "Mira.h"
#include "Personajes.h"
#include <ctime>


using namespace sf;
using namespace std;

class Juego {
    RenderWindow* _ventana;
    Texture saloon;
    Sprite _salon;
    Mira* mira;
    Personajes* personajes;
    Clock _clock;
    Texture ventana1t;
    Sprite ventana1s;
    Texture ventana12t;
    Sprite ventana12s;
    Texture ventana2t;
    Sprite ventana2s;
    Texture ventana22t;
    Sprite ventana22s;
    int puntosB=3;
    int puntosM = 0;
    Text puntaje;
    Text puntajeM;
    Font fuente;
    Texture puntajeBt;
    Texture puntajeMt;
    Sprite puntajeBs;
    Sprite puntajeMs;
    Texture gameovert;
    Sprite gameovers;
    Texture wint;
    Sprite wins;
    Clock tiempo;
    Time _tiempo;

    //Se crean sprites, texturas y variables a utilizar.


    public:
     Juego() {
            ventana12t.loadFromFile("ventana1-2.png");
            ventana12s.setTexture(ventana12t);
            ventana22t.loadFromFile("ventana2-2.png");
            ventana22s.setTexture(ventana22t);
            _ventana = new RenderWindow(VideoMode(800, 900), "Vaqueros");
            mira = new Mira;
            saloon.loadFromFile("salon.png");
            _salon.setTexture(saloon);            
            personajes = new Personajes;
            puntaje.setScale(1, 1);
            puntaje.setPosition(600, 630);
            puntaje.setCharacterSize(30);
            fuente.loadFromFile("fuente.ttf");
            puntaje.setFont(fuente);
            puntajeM.setScale(1, 1);
            puntajeM.setPosition(600, 700);
            puntajeM.setCharacterSize(30);
            puntajeM.setFont(fuente);
            puntajeBt.loadFromFile("puntajebuenos.png");
            puntajeMt.loadFromFile("puntajemalos.png");
            puntajeBs.setTexture(puntajeBt);
            puntajeMs.setTexture(puntajeMt);
            puntajeBs.setPosition(400,620);
            puntajeBs.setScale(0.6, 0.6);
            puntajeMs.setPosition(317,673);
            gameovert.loadFromFile("gameover.png");
            wint.loadFromFile("win.png");
            gameovers.setTexture(gameovert);
            wins.setTexture(wint);
            //Se crean objetos de ciertas clases, y se aplican las texturas a los sprites a utilizar, modificando opciones de estos sprites.
     }
     void actualizarPuntajeB();//actualiza el ppuntaje de personajes buenos que vamos matando.
     void actualizarPuntajeM();//actualiza el ppuntaje de personajes malos que vamos matando.
     void Loop();//loop a repetir para que el juego corra.
     void ProcesarEventos();//donde se encuentran todos los eventos a procesar del juego, teclado mouse y demas.
     void Actualizar();//actualiza los personajes.
     void Dibujar();//dibuja todos los sprites a utilizar.
     void Disparar();//al disparar, suma puntajes, detecta colisiones y respawneos de personajes fuera de pantalla.
     int terminarJuego();

    ~Juego() {//destructores.
          delete personajes;
          delete mira;
          delete _ventana;
    }
};
#endif
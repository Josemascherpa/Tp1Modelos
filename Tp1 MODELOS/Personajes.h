#ifndef PERSONAJES_H
#define PERSONAJES_H
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <iostream>

using namespace std;

using namespace sf;

class Personajes {
	Texture Enemigo1;
	Texture Enemigo2;
	Texture Bueno1;
	Texture Bueno2;
	//Se crean las texturas y sprites de personajes.

	bool _estavivo;
	bool _estavisible;
	Clock _clock;
	float _tiempovisible = 1.0f;
	float _tiempoapagado = 1.0f;
	Sprite Personajess[4];//se crea el arreglo de sprites.

	Vector2f randomPos(Vector2u maxpos);//Se crea un switch de posiciones random
	
	
	public:
		Personajes() {
			Enemigo1.loadFromFile("enemigo1.png");
			Enemigo2.loadFromFile("enemigo2.png");
			Bueno1.loadFromFile("bueno1.png");
			Bueno2.loadFromFile("bueno2.png");
			//texturas y sprites de personajes y se los aplica al arreglo.

			Personajess[0].setTexture(Enemigo1);	
			Personajess[0].setScale(0.9, 1.5);
			Personajess[1].setTexture(Enemigo2);
			Personajess[1].setScale(1, 1.5);
			Personajess[2].setTexture(Bueno1);
			Personajess[2].setScale(1, 1.5);
			Personajess[3].setTexture(Bueno2);
			Personajess[3].setScale(1, 1.5);
		
			

			
			_estavivo = true;
			_estavisible = false;
		}
		void Dibujar(RenderWindow* wind);//funcion dibujar personajes.
		
		bool _EstaActivo();//Retorna si esta vivo o no.
		
		bool EstaEncima1(float x, float y);//funcion para detectar si la mira esta encima del personaje o no.
		bool EstaEncima2(float x, float y);
		bool EstaEncima3(float x, float y);
		bool EstaEncima4(float x, float y);
		void Derrotar();//metodo que si se le dispara a un personaje, saca de pantalla al personaje al que se le disparo.
		void Actualizar(RenderWindow* wind);//actualiza posiciones de personajes.
		
		
};



#endif
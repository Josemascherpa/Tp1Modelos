#ifndef MIRA_H
#define MIRA_H
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"


using namespace sf;
using namespace std;


class Mira {
	Texture Mirat;
	Sprite Miras;

public:
	Mira() {
		Mirat.loadFromFile("Mira.png");//Se carga la textura para el sprite Mira.
		Miras.setTexture(Mirat);//Al sprite Mira , se le setea la textura Mirat.
		Miras.setOrigin(Mirat.getSize().x / 2.0f, Mirat.getSize().y / 2.0f);//Se setea la mira en el medio del cursor.
		Miras.setScale(0.6f, 0.6f);//se setea la escala, o sea tamaño, de la mira.
		
	}

	void Dibujar(RenderWindow* wind);//se dibuja mira.
	void Posicionar(float x, float y);//se posiciona mira en el cursor.

	Vector2f ObtenerPosicion() {
		return Miras.getPosition();
	}


};



#endif
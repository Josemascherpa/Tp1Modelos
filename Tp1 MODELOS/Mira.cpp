#include "Mira.h"
#include "Juego.h"

using namespace sf;
using namespace std;

void Mira::Dibujar(RenderWindow* wind) {
	wind->draw(Miras);//Se dibuja mira, pasando por parametro una ventana.
}

void Mira::Posicionar(float x, float y) {
	Miras.setPosition(x, y);//se setea posicion de mira.
}


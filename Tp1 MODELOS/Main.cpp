#include <iostream>
#include "Juego.h"
#include <ctime>

using namespace std;

int main() {
	srand(time(NULL));
	Juego J;//se crea un objeto de clase Juego, y se llama a la funcion Loop de esa Clase.
	J.Loop();

	return 0;
}
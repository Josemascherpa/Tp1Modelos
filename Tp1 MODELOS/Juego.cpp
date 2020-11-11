#include "Juego.h"



using namespace sf;


void Juego::Loop() {
	while (_ventana->isOpen()) {
		ProcesarEventos();
		Actualizar();
		Dibujar();
		if (terminarJuego() != 0) {//Cerramos el juego, dependiendo el return del metodo.
			if (terminarJuego() == 1) {
				_tiempo = tiempo.getElapsedTime();//igualamos el clock al time.
				if (_tiempo.asSeconds() > 10) {
					_ventana->close();//cierra ventana
				}
			}
			if (terminarJuego() == 2) {
				_tiempo = tiempo.getElapsedTime();
				if (_tiempo.asSeconds() > 10) {
					_ventana->close();
				}
			}
		}
	}
	

}
void Juego::actualizarPuntajeB() {
	char pts[30];
	_itoa_s(puntosB, pts, 10);
	puntaje.setString(pts);
	puntaje.setString(pts);
}
void Juego::actualizarPuntajeM() {
	char pts[30];
	_itoa_s(puntosM, pts, 10);
	puntajeM.setString(pts);
	puntajeM.setString(pts);
}


void Juego::ProcesarEventos() {
	Event evt;
	while (_ventana->pollEvent(evt)) {
		switch (evt.type) {
		case Event::Closed://evento de cerrar ventana.
			_ventana->close();
			break;
		case Event::MouseMoved://evento de si movemos el mouse, que la mira se posicione en el mismo lugar.
			mira->Posicionar(evt.mouseMove.x, evt.mouseMove.y);
			break;
		case Event::MouseButtonPressed://que el mouse dispare al hacer click.
			if (evt.mouseButton.button == Mouse::Button::Left) {
				Disparar();
			}
			break;
		}
	}


}
void Juego::Actualizar() {
	
	personajes->Actualizar(_ventana);
	

}
void Juego::Disparar() {
	Vector2f playerPos = mira->ObtenerPosicion();
	if (personajes->_EstaActivo()) {

		if (personajes->EstaEncima1(playerPos.x, playerPos.y)) {
			personajes->Derrotar();
			puntosM++;
			cout << "Derrotado personaje malo" << endl;
		}
		if (personajes->EstaEncima2(playerPos.x, playerPos.y)) {
			personajes->Derrotar();
			puntosM++;
			cout << "Derrotado personaje malo" << endl;
		}
		if (personajes->EstaEncima3(playerPos.x, playerPos.y)) {
			personajes->Derrotar();
			puntosB--;
			cout << "Derrotado personaje bueno" << endl;
		}
		if (personajes->EstaEncima4(playerPos.x, playerPos.y)) {
			personajes->Derrotar();
			puntosB--;
			cout << "Derrotado personaje bueno" << endl;
		}
		
		
	}
	
	
		
	actualizarPuntajeB();
	actualizarPuntajeM();
	
	
}
int Juego::terminarJuego() {
	if (puntosB == 0) {
		gameovers.setScale(2, 2);
		gameovers.setPosition(1, 1);
		_ventana->draw(gameovers);
		return 1;

	}
	if (puntosM == 10) {
		wins.setScale(2, 2);
		wins.setPosition(1, 1);
		_ventana->draw(wins);
		return 2;
	}
	return 0;
}

void Juego::Dibujar() {//metodo encargado de limpiar pantalla, dibujar todo lo del juego.
	_ventana->clear();
	
	
	if (personajes->_EstaActivo()){
		
		
		_ventana->draw(ventana12s);
		ventana12s.setPosition(77, 86.2);
		ventana12s.setScale(3.12, 3.1);
		_ventana->draw(ventana22s);
		ventana22s.setPosition(525, 85.9);
		ventana22s.setScale(3.12, 3.1);
		_ventana->draw(ventana12s);
		ventana12s.setPosition(46.8, 333);
		ventana12s.setScale(3.3, 3.64);
		_ventana->draw(ventana22s);
		ventana22s.setPosition(549, 333);
		ventana22s.setScale(3.12, 3.1);
		
		personajes->Dibujar(_ventana);
		
	}
	
	
	
	
	_ventana->draw(_salon);
	terminarJuego();
	_ventana->draw(puntaje);
	_ventana->draw(puntajeM);
	mira->Dibujar(_ventana);
	_ventana->draw(puntajeBs);
	_ventana->draw(puntajeMs);
	_ventana->display();


}

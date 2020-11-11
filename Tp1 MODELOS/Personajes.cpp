#include "Personajes.h"

using namespace sf;
using namespace std;

void Personajes::Dibujar(RenderWindow *wind) {//se dibuja personajes en pantalla.
	for (int i = 0; i < 4; i++)
	{
		wind->draw(Personajess[i]);
		
	}
	
	
}


bool Personajes::EstaEncima1(float x, float y) {//funciones para detectar la posicion de los personajes y ver si esta encima o no.
	FloatRect bounds1 = Personajess[0].getGlobalBounds();
	
	return bounds1.contains(x, y);
	
	
}
bool Personajes::EstaEncima2(float x, float y) {
	
	FloatRect bounds2 = Personajess[1].getGlobalBounds();
	
	return bounds2.contains(x, y);
	
}
bool Personajes::EstaEncima3(float x, float y) {

	FloatRect bounds3 = Personajess[2].getGlobalBounds();
	
	return bounds3.contains(x, y);

}
bool Personajes::EstaEncima4(float x, float y) {

	FloatRect bounds4 = Personajess[3].getGlobalBounds();
	
	return bounds4.contains(x, y);
	

}
void Personajes::Derrotar() {//si se derrota o sea , dispara un personaje, los manda a una posicion fuera de pantalla.
	
	for (int i = 0; i < 4; i++)
	{
		Personajess[i].setPosition(1000, 1000);
	}
		
	

	
	

}



bool Personajes::_EstaActivo() {
	return _estavivo;
}
void Personajes::Actualizar(RenderWindow* wind) {
	if (!_estavivo) {
		return;
	}
		
	if (!_estavisible) {
		if (_clock.getElapsedTime().asSeconds() > _tiempoapagado) {//si el tiempo que paso es mayor al tiempo apagado, que reinicie y el tiempo, y respawnee personajes random.
			_clock.restart();
			if (rand() % 100 < 100) {//posibilidades de que aparezcan.
				_estavisible = true;
							
				
				switch (rand()%4)//switch respawn
				{
					case 0: {
						Personajess[0].setPosition(randomPos(wind->getSize()));
						break;
					}
					case 1: {
						Personajess[1].setPosition(randomPos(wind->getSize()));
						break; }
					case 2: {
						Personajess[2].setPosition(randomPos(wind->getSize()));
						break; }
					case 3: {
						Personajess[3].setPosition(randomPos(wind->getSize()));
						break; }
					default:break;
				}
			
				
				
				
			}

		}
		
	}
	else{
		if (_clock.getElapsedTime().asSeconds() > _tiempovisible) {//si pasa un tiempo y no se les dispara, que los mueva a una posicion fuera de la pantalla. 
			_estavisible = false;
			Personajess[0].setPosition(1000, 1000);
			Personajess[1].setPosition(1000, 1000);
			Personajess[2].setPosition(1000, 1000);
			Personajess[3].setPosition(1000, 1000);
			_clock.restart();
		}
					
			
	}





}


Vector2f Personajes::randomPos(Vector2u maxpos) {
	

	switch (rand()%5+1) {
		case 1: {
			Vector2f random1(maxpos.x = 135, maxpos.y = 110);
			return random1; break;
		}
		case 2: {
			Vector2f random2(maxpos.x = 110, maxpos.y = 370);
			return random2; break;
		}
		case 3: {
			Vector2f random3(maxpos.x = 580, maxpos.y = 110);
			return random3; break;
		}
		case 4: {
			Vector2f random4(maxpos.x = 360, maxpos.y = 370);
			return random4; break;
		}
		case 5: {
			Vector2f random4(maxpos.x = 600, maxpos.y = 370);
			return random4; break;
		}
		default:break;
	}
	
}
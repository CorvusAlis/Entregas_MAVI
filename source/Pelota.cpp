#include "Pelota.h"

//crea una pelota con valores predeterminados
Pelota::Pelota() {
	posicion = { 400, 225 }; //el centro de la pelota - inicia en el centro ventana
	velocidad = { 250, 150 };	//ver con que velocidad se actualiza el movimiento
	radio = 30;
	color = { 0, 121, 241, 200 };	//200 en alpha para transparencia
	rebotes = 0; //empieza contador en 0 rebotes
}

void Pelota::DibujarPelota() const {
	DrawCircleV(posicion, radio, color); //DrawCircleV acepta vectores (posicion)
}

void Pelota::MoverPelota() {
	//el vector velocidad determina cuantas unidades aumenta o disminuye el valor de la posicion
	//para simular el movimiento, se le suma al vector posicion en x/y el valor del vector velocidad en x/y
	//la funcion GetFrameTime permite que el movimiento sea independiente de los FPS (rendimiento de la PC) - la velocidad real es la misma a cualquier rendimiento
	float deltaTime = GetFrameTime();

	posicion.x += velocidad.x * deltaTime;
	posicion.y += velocidad.y * deltaTime;

	//para simular el rebote, cuando la pelota encuentre un borde, el vector velocidad cambia de direccion (*-1)
	//se suma el radio a la posicion para que choque el borde de la pelota y no el centro

	if (posicion.x + radio >= GetScreenWidth() || posicion.x - radio <= 0) {
		velocidad.x *= -1; //cambio direccion
		CambiarColor();
		rebotes += 1;
	}

	if (posicion.y + radio >= GetScreenHeight() || posicion.y - radio <= 0) {
		velocidad.y *= -1; //cambio direccion
		CambiarColor();
		rebotes += 1;
	}
}

void Pelota::CambiarColor() {
	//unsigned char por conversion de datos
	color = {
	(unsigned char)GetRandomValue(50, 255),
	(unsigned char)GetRandomValue(50, 255),
	(unsigned char)GetRandomValue(50, 255),
	200
	};
}
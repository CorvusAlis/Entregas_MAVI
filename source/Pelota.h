#pragma once
#include <iostream>
#include "raylib.h"

using namespace std;

class Pelota {

	//Atributos privados
private:
	Color color;
	Vector2 posicion;	//ubicacion del centro de la pelota
	Vector2 velocidad;	//velocidad con la que se movera la pelota por la ventana
	float radio;	//determina el borde de la pelota
	int rebotes;

	//Atributos publicos
public:

	//constructor
	Pelota();

	//getter (obtiene valor de atributos)
	int GetRebotes() const { return rebotes; }
	Vector2 GetPosicion() const { return posicion; }

	void DibujarPelota() const;	//crea un circulo
	void MoverPelota();
	void CambiarColor();

};

#pragma once
#include <iostream>
#include "raylib.h"
#include "Pelota.h"

using namespace std;

//Armado constructor clase Ventana

class Ventana {

//Atributos privados
private:
	string nombre;
	string mensaje1;
	string mensaje2;
	bool toggleMensaje;

//Atributos publicos
public:
	//Metodos publicos - en Ventana.cpp se definen los metodos
	Ventana(string n1, string m1, string m2);
	void EntradaBoton();
	void CargaVentana();
	void InfoPelota(const Pelota& p);
};

#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif
#include "raylib.h"
#include "Ventana.h"
#include "Pelota.h"

using namespace std;

int anchoVentana = 1024;
int altoVentana = 768;

int main(void)
{
    //Init ventana
    InitWindow(anchoVentana, altoVentana, "Carta de Presentacion - Barbara Tobares");

    //Creacion de objetos
    Ventana ventana("Barbara Tobares", "Que le dijo un arbol a otro?", "Nada, los arboles no hablan!");
    Pelota pelota;

    // Bucle principal - print de mensaje y deteccion de tecla presionada
    while (!WindowShouldClose())
    {
        //Control para tecla
        ventana.EntradaBoton();

        //Print del contenido de la ventana
        BeginDrawing();
        ventana.CargaVentana();
        ventana.InfoPelota(pelota);
        pelota.DibujarPelota();
        pelota.MoverPelota();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}


#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif
#include "raylib.h"
#include "Ventana.h"

using namespace std;

int anchoVentana = 900;
int altoVentana = 600;

int main(void)
{
    //Init ventana
    InitWindow(anchoVentana, altoVentana, "Carta de Presentacion - Barbara Tobares");

    //Se crea el objeto ventana con el mensaje principal y los mensajes secudarios
    Ventana ventana("Barbara Tobares", "Que le dijo un arbol a otro?", "Nada, los arboles no hablan!");

    // Bucle principal - print de mensaje y deteccion de tecla presionada
    while (!WindowShouldClose())
    {
        //Control para tecla
        ventana.EntradaBoton();

        //Print del contenido de la ventana
        BeginDrawing();
        ventana.CargaVentana();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}


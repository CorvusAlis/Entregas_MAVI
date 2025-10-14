#include "Ventana.h"	//se incluye el constructor de Ventana
#include "Pelota.h"

//Objeto tipo Ventana con atributos del constructor - se asignan los atributos que se reciben a los atributos declarados
Ventana::Ventana(string n1, string m1, string m2) {
	nombre = n1;
	mensaje1 = m1;
	mensaje2 = m2;
	toggleMensaje = false;
}

//Se definen las funcionalidades de los metodos publicos

void Ventana::CargaVentana() {
	//Carga de la ventana inicial

	//Tama�o
	int ventanaX = GetScreenWidth(); //ancho
	int ventanaY = GetScreenHeight(); //alto

	//Color fondo
	ClearBackground(DARKPURPLE);

	//Texto
	int tamTexto = 45;
	int textAncho = MeasureText(nombre.c_str(), tamTexto);

	//Print texto principal
	//Posicionamiento del texto centrado en la ventana
	int texto1X = (ventanaX - textAncho) / 2;
	int texto1Y = (ventanaY - tamTexto) / 2;
	DrawText(nombre.c_str(), texto1X, texto1Y, tamTexto, WHITE);

	//Texto con cambio
	const char* msjMostrado = mensaje1.c_str();
	if (toggleMensaje) {
		msjMostrado = mensaje2.c_str();
	}
	else if (!toggleMensaje) {
		msjMostrado = mensaje1.c_str();
	}

	int tamTexto2 = 35;
	int textoAncho2 = MeasureText(msjMostrado, tamTexto2);
	int padding = 30;	//borde de rectangulo adicional
	int separacion = 100;
	
	//Toma el ancho y alto del texto para dibujar el rectangulo segun el tama�o
	int rectAncho = textoAncho2 + padding;
	int rectAlto = tamTexto2 + padding;
	//Toma el alto y ancho de la ventana para determinar la posicion de inicio de dibujado
	int rectX = (ventanaX - rectAncho) / 2;
	int rectY = texto1Y + tamTexto + separacion; //el rectangulo se mueve segun el texto principal segun una separacion de 100 unidades
	

	//Definicion de la figura
	Rectangle rectangulo = { rectX, rectY, rectAncho, rectAlto };

	DrawRectangleRounded(rectangulo, 0, 0, LIME);

	//Posicionamiento del texto dentro del rectangulo
	int texto2X = rectX + (rectAncho - textoAncho2) / 2;
	int texto2Y = rectY + (rectAlto - tamTexto2) / 2;

	//Print del texto con cambio
	DrawText(msjMostrado, texto2X, texto2Y, tamTexto2, BLACK);
	//DrawText(msjMostrado, (ventanaX - textoAncho2) / 2, ventanaY / 2 + 100, tamTexto2, BLACK);

}

void Ventana::EntradaBoton() {
	if (IsKeyPressed(KEY_SPACE)) {
		toggleMensaje = !toggleMensaje;	//cambia el estado del bool toggleMensaje al contrario
	}
}

void Ventana::InfoPelota(const Pelota& p) {
	//paso el valor por referencia de la pelota para evitar copiar todo el objeto en cada frame
	//como es const no se puede modificar desde Ventana
	Vector2 posPelota = p.GetPosicion();

	int ventanaX = GetScreenWidth(); //ancho
	int ventanaY = GetScreenHeight(); //alto

	DrawText(TextFormat("Rebotes: %d", p.GetRebotes()), 10, 10, 20, RAYWHITE);
	DrawText(TextFormat("Posicion actual: %.2f , %.2f", posPelota.x, posPelota.y ), 10, ventanaY - 30, 20, RAYWHITE);	//%.2f muestra dos numero luego de la coma, Vector2 es (float,float)
	DrawText(TextFormat("Resolucion: %d x %d", ventanaX, ventanaY), ventanaX - 240, ventanaY - 30, 20, RAYWHITE);	//ver de implementar dinamico como en subtitulo
}
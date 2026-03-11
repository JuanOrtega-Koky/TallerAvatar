// Curso: Fundamentos de Programación Orientada a Objetos
// Archivo: avatar.cpp
// Autores:
// - Juan Manuel Ortega Leal | Código: 2535112 | juan.ortega.leal@correounivalle.edu.co
// - María Camila Zuleta Peña | Código: 2540542 | maria.camila.zuleta@correounivalle.edu.co
// - Juan José Peña Garcés | Código: 2538880 | juan.jose.pena@correounivalle.edu.co
// Fecha: 10/03/2026
// incluir la clase
#include "Avatar.h"
#include "Tablero.h"
#include <iostream>
#include <string>
#include <vector>
// Librerias para generar el aleatorio
#include <stack>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Constructor
Avatar::Avatar(Tablero& auxmapa):mapa(auxmapa) {
	//Se inicializa el avatar en la posicion 1 en la fila y 1 en la columna
	posX = 1;
	posY = 1;
	ruta.resize(0);//Se inicializa el vector de rutas
	posiblesCaminosX.empty();//se inicializa los vectores de posibles caminos en X
	posiblesCaminosY.empty();//se inicializa los vectores de posibles caminos en Y
}

void Avatar::mapearNuevosCaminos() {
	guardarPosibleCamino(posX, posY - 1); // atrás
	guardarPosibleCamino(posX - 1, posY); // arriba
	guardarPosibleCamino(posX + 1, posY); // abajo
	guardarPosibleCamino(posX, posY + 1); // adelante
}

// Mover el Avatar
void Avatar::moverAvatar() {
	posX = posiblesCaminosX.top();
	posiblesCaminosX.pop();
	posY = posiblesCaminosY.top();
	posiblesCaminosY.pop();
}

void Avatar::guardarPosibleCamino(int x, int y) {

	if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9)) {
		if (mapa.getCelda(x, y) == 1) {
			posiblesCaminosX.push(x);
			posiblesCaminosY.push(y);
		}
    
	}
}

void Avatar::mostrarCaminosPosibles() {
	stack<int> auxX;
	stack<int> auxY;
	int auxTam = posiblesCaminosX.size();
	auxX = posiblesCaminosX;
	auxY = posiblesCaminosY;

	for (int i = 0; i < auxTam; i++) {
		cout << "posible camino en x: " << auxX.top() << "  ";
		auxX.pop();
		cout << "posible camino en y: " << auxY.top() << endl;
		auxY.pop();
	}
	//cout << posiblesCaminosX.size() << endl;
}

int Avatar::getPosX() {
	return posX;
}

int Avatar::getPosY() {
	return posY;
}

void Avatar::guardarRuta() {
	vector<int> aux;
	aux.resize(0);
	aux.push_back(posX);
	aux.push_back(posY);
	ruta.push_back(aux);
}

void Avatar::imprimirSolucion() {
	for (int i = 0; i < ruta.size(); i++) {
		cout << "[x:" << ruta[i][0] << " y:" << ruta[i][1] <<"]"<< endl;
	}
}

bool Avatar::metaEncontrada() {
	if (posX == 9 && posY == 9){
		return true;
	}else{
		return false;
	}
}

void Avatar::imprimirPosicion(){
	cout<<"La posicion del avatar es: ["<< posX <<","<< posY <<"]"<< endl;
}


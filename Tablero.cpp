// incluir la clase
#include "Tablero.h"
#include <vector>
// libreria para el manejo de archivos planos
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Constructor
Tablero::Tablero()
{
  laberinto.resize(0); //Se inicializa el laberinto en vacio
  nivel = "";
}


void Tablero::cargarTablero(string nombreDelArchivo)
{
  // Abrir el archivo plano
  ifstream flujoDatos(nombreDelArchivo);
  // capturar la información linea a linea del archivo plano
  string linea;
  string aux;
  // Recorrer el archivo plano
  while(getline(flujoDatos, linea)){
    vector <int> auxVector;
    for(int j=0; j<19; j = j+2){
      aux = linea.substr(j, 1);
      auxVector.push_back(stoi(aux));// Cargar el laberinto (atributo) y transformar el dato char a int
    }
    laberinto.push_back(auxVector);// Cargar el laberinto (atributo)
  }
}


void Tablero::mostrarTablero()
{
  for(int x=0; x<10; x++){
    for(int y=0; y<10; y++){
      cout << laberinto[x][y] << " ";
    }
    cout << endl;
  }
}

int Tablero::getCelda(int x, int y)
{
  return laberinto[x][y]; // Retorna "0" o "1" del tablero
}


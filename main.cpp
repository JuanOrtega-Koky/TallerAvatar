/**
 * @file main.cpp
 * @brief Punto de entrada del sistema de exploración de laberinto.
 *
 * @details
 * Este archivo contiene la función principal del programa. Se encarga
 * de orquestar la interacción entre las clases Tablero y Avatar,
 * instanciando los objetos necesarios y ejecutando la secuencia lógica
 * para la exploración del laberinto y la impresión de la solución.
 *
 *
 * Flujo general del programa:
 *   1. Se instancia el tablero.
 *   2. Se crea el avatar pasando el tablero (modificarlo para pasar por referencia)
 *   3. Se inicializa la ruta.
 *   4. Se exploran posibles caminos.
 *   5. Se ejecuta un movimiento del avatar.
 *   6. Se almacena la ruta.
 *   7. Se imprime la solución de un paso.
 *
 * -----------------------------------------------------------------------------
 *
 * @author Victor Bucheli
 * @email victor.bucheli@correounivalle.edu.co
 * @license GNU General Public License v3.0 (GPL)
 *
 * Este programa es software libre: puede redistribuirlo y/o modificarlo
 * bajo los términos de la Licencia Pública General de GNU publicada por
 * la Free Software Foundation, ya sea la versión 3 de la Licencia, o
 * (a su elección) cualquier versión posterior.
 *
 * Este programa se distribuye con la esperanza de que sea útil,
 * pero SIN NINGUNA GARANTÍA; incluso sin la garantía implícita de
 * COMERCIABILIDAD o IDONEIDAD PARA UN PROPÓSITO PARTICULAR.
 * Véase la Licencia Pública General de GNU para más detalles.
 *
 * Debería haber recibido una copia de la Licencia Pública General de GNU
 * junto con este programa. Si no, consulte <https://www.gnu.org/licenses/>.
 */
// Se incluye la clase
#include "Avatar.h"
#include "Tablero.h"
#include <iostream>
using namespace std;

int main() {
//Instaciar los objetos
	Tablero mapa;
	mapa.cargarTablero("tablero.txt");//se carga el tablero desde un archivo plano
	mapa.mostrarTablero();
	Avatar jugador(mapa);
//Interacción de objetos
  	jugador.guardarRuta();
  	cout<<"Hubicación actual del Avatar en el tablero: ";
  	jugador.imprimirSolucion();
	jugador.mapearNuevosCaminos();
	jugador.mostrarCaminosPosibles();
	jugador.moverAvatar();
  	jugador.guardarRuta();
  	cout<<"Ruta recorrida por el Avatar en el tablero:"<<endl;
  	jugador.imprimirSolucion();
return 0;
}
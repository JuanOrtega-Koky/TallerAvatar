/**
 * @file Avatar.h
 * @brief Definición de la clase Avatar.
 *
 * @details
 * Implementa la entidad Avatar dentro de un entorno representado por un
 * objeto de la clase Tablero. El Avatar es responsable de recorrer el
 * tablero, gestionar posibles caminos mediante estructuras tipo pila
 * (stack) y almacenar la ruta recorrida hasta encontrar una solución.
 *
 * -----------------------------------------------------------------------------
 * Estándar CRC (Clase - Responsabilidad - Colaboración)
 * -----------------------------------------------------------------------------
 *
 * Clase:
 *   Avatar
 *
 * Responsabilidades:
 *   - Mantener la posición actual del avatar en el tablero (posX, posY).
 *   - Gestionar y almacenar la ruta recorrida.
 *   - Identificar y almacenar posibles caminos mediante pilas.
 *   - Explorar nuevos caminos dentro del tablero.
 *   - Imprimir la solución encontrada.
 *   - Interactuar con el tablero para validar movimientos.
 *
 * Colaboradores:
 *   - Tablero:
 *       * Proporciona el entorno sobre el cual el Avatar se desplaza.
 *       * Permite consultar información del mapa.
 *       * Se establece una relación de colaboración por referencia.
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

// Candado: Evita la doble declaración
#ifndef _AVATAR_H_
#define _AVATAR_H_
#include "Tablero.h"
#include <stack>
#include <string>
#include <vector>
using namespace std;

// Nombre clase
class Avatar {
	// atributos
private:
	int posX; //Posicion en las filas
	int posY; //posicion en las columnas
	vector<vector<int>> ruta; //almacena la posX y posY de la ruta que ha tomado el avatar
	Tablero mapa; //modificar el codigo para que el mapa se obtiene por referencia
	stack<int> posiblesCaminosX; //Consultar sobre el manejo de las pilas acá se apilan posibles caminos en las filas
	stack<int> posiblesCaminosY;//Consultar sobre el manejo de las pilas acá se apilan posibles caminos en las columnas

	// métodos
public:
	// Método constructor
	Avatar(Tablero auxmapa);//modificar el codigo para que el mapa se obtiene por referencia; Permite cargar el tablero desde un archivo.txt
	void moverAvatar(); //Permite que el avatar se mueva por el laberinto siempre a la derecha
	int getPosX(); 
	int getPosY();
	void guardarPosibleCamino(int x, int y);//Apila posibles caminos a tomar por el avatar
	void guardarRuta();//Almacena la ruta que lleva el avatar
	void mostrarCaminosPosibles();//Muestra los posibles camios
	void mapearNuevosCaminos();//Busca nuevos caminos implementar en el punto extra
	void imprimirSolucion();
	bool metaEncontrada();
	void imprimirPosicion();
};
// Cierro el candado
#endif
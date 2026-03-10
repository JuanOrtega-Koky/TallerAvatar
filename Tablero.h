/**
 * @file Tablero.h
 * @brief Definición de la clase Tablero.
 *
 * @details
 * Implementa la abstracción del entorno de juego representado como un
 * laberinto bidimensional. La clase Tablero es responsable de gestionar
 * la estructura interna del mapa, permitir su carga desde archivo,
 * visualizarlo en pantalla y ofrecer acceso controlado a sus celdas.
 *
 * -----------------------------------------------------------------------------
 * Estándar CRC (Clase - Responsabilidad - Colaboración)
 * -----------------------------------------------------------------------------
 *
 * Clase:
 *   Tablero
 *
 * Responsabilidades:
 *   - Representar el laberinto como una matriz bidimensional.
 *   - Cargar la configuración del tablero desde un archivo externo (.txt).
 *   - Mostrar gráficamente el tablero en consola.
 *   - Proporcionar acceso controlado a las celdas del laberinto.
 *   - Gestionar y almacenar el nivel actual del juego.
 *
 * Colaboradores:
 *   - Avatar:
 *       * Consulta el estado de las celdas del tablero.
 *       * Utiliza la información del laberinto para validar movimientos.
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
#ifndef _TABLERO_H_
#define _TABLERO_H_
#include <vector>
#include <string>
using namespace std;

// Nombre clase
class Tablero
{
  // atributos
  private: 
    vector <vector <int> > laberinto;//un vector de vectores de 1 o 0 donde hay camino o precipicio
    string nivel; //Almacena el nivel del juego
    

  // métodos
  public:
 
    Tablero();   // Método constructor
    void cargarTablero(string nombreDelArchivo);// Permite cargar el tablero desde un archivo .txt
    void mostrarTablero();// Muestra el tablero en pantalla
    int getCelda(int x, int y);// Retorna "0" o "1" del tablero
    int getNivel();    // Retorna el nivel del juego
};
// Cierro el candado
#endif
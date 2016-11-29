////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
   Programa que calcula el reparto de beneficios entre cuatro destinatarios,
   siendo las proporciones diferentes: el destinatario 1 (diseñador) recibe
   el doble que los otros tres (fabricantes).

   Entradas: beneficio a repartir
   Salidas:  ganancia del diseñador y ganancia de los fabricantes
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main(){
	double beneficio; 	// Dato de entrada

	cout << "\nIntroduzca beneficio obtenido: ";
	cin >> beneficio;

/*
	En esta primera solución se ofrece la salida pedida,
	pero tiene dos inconvenientes:

	1.	Repetimos el cálculo beneficio/5 dos veces.
		Repetir código es propenso a errores ya que cualquier actualización en el futuro
        nos obliga a modificar todas las instrucciones que contienen dichas repeticiones.

	2.	En la misma sentencia de salida de resultados realizamos los cómputos.
		Debemos separar las entradas de datos de los cómputos y de las
		salidas de resultados.
*/

	cout << "\nGanancia de cada fabricante: " << beneficio/5;        // :-(
	cout << "\nGanancia del diseñador: "      << 2 * beneficio/5;    // :-(
	cout << "\n\n";

	// Lo arreglamos añadiendo dos variables y realizando los cálculos
	// antes de mostrar los resultados.

	double ganancia_diseniador, ganancia_fabricante;  // Datos de salida

	ganancia_fabricante = beneficio/5;
	ganancia_diseniador = 2 * ganancia_fabricante;

	cout << "\nGanancia de cada fabricante: " << ganancia_fabricante;        // :-)
	cout << "\nGanancia del diseñador: "      << ganancia_diseniador;        // :-)
	cout << "\n\n";

	// Si tuviésemos que modificar el número de fabricantes de 5 a 6, por ejemplo,
	// bastaría con modificar una única línea
	//		ganancia_fabricante = beneficio/5;  --> ganancia_fabricante = beneficio/6;
	// mientras que en la solución inicial, como repetíamos código,
	// había que cambiarlo en dos sitios distintos.

	// Nota: Si el número de fabricantes es un dato que puede cambiar
	// de una ejecución a otra del programa, entonces, tendríamos que
	// haber usado una variable y leerla desde el teclado (dispositivo de entrada de datos):

	// double num_fabricantes;
	// cin >> num_fabricantes;
	// ...
	// ganancia_fabricante = beneficio / num_fabricantes;

	system("pause");
}

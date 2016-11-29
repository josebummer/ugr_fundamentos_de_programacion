////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
   Programa que calcula el reparto de beneficios entre cuatro destinatarios,
   siendo las proporciones diferentes: el destinatario 1 (dise�ador) recibe
   el doble que los otros tres (fabricantes).

   Entradas: beneficio a repartir
   Salidas:  ganancia del dise�ador y ganancia de los fabricantes
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main(){
	double beneficio; 	// Dato de entrada

	cout << "\nIntroduzca beneficio obtenido: ";
	cin >> beneficio;

/*
	En esta primera soluci�n se ofrece la salida pedida,
	pero tiene dos inconvenientes:

	1.	Repetimos el c�lculo beneficio/5 dos veces.
		Repetir c�digo es propenso a errores ya que cualquier actualizaci�n en el futuro
        nos obliga a modificar todas las instrucciones que contienen dichas repeticiones.

	2.	En la misma sentencia de salida de resultados realizamos los c�mputos.
		Debemos separar las entradas de datos de los c�mputos y de las
		salidas de resultados.
*/

	cout << "\nGanancia de cada fabricante: " << beneficio/5;        // :-(
	cout << "\nGanancia del dise�ador: "      << 2 * beneficio/5;    // :-(
	cout << "\n\n";

	// Lo arreglamos a�adiendo dos variables y realizando los c�lculos
	// antes de mostrar los resultados.

	double ganancia_diseniador, ganancia_fabricante;  // Datos de salida

	ganancia_fabricante = beneficio/5;
	ganancia_diseniador = 2 * ganancia_fabricante;

	cout << "\nGanancia de cada fabricante: " << ganancia_fabricante;        // :-)
	cout << "\nGanancia del dise�ador: "      << ganancia_diseniador;        // :-)
	cout << "\n\n";

	// Si tuvi�semos que modificar el n�mero de fabricantes de 5 a 6, por ejemplo,
	// bastar�a con modificar una �nica l�nea
	//		ganancia_fabricante = beneficio/5;  --> ganancia_fabricante = beneficio/6;
	// mientras que en la soluci�n inicial, como repet�amos c�digo,
	// hab�a que cambiarlo en dos sitios distintos.

	// Nota: Si el n�mero de fabricantes es un dato que puede cambiar
	// de una ejecuci�n a otra del programa, entonces, tendr�amos que
	// haber usado una variable y leerla desde el teclado (dispositivo de entrada de datos):

	// double num_fabricantes;
	// cin >> num_fabricantes;
	// ...
	// ganancia_fabricante = beneficio / num_fabricantes;

	system("pause");
}

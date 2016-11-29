/* Indicar si se produce un problema de precisión o de desbordamiento en los siguientes ejemplos 
indicando cuál será el resultado final de las operaciones. */

#include <iostream>

using namespace std;

int main (){
	
	//c)
	double resultado, real1, real2; 		// Creamos las variables
	
	real1 = 123.1;								// Damos valores a algunas de ellas
	real2 = 124.2;
	
	resultado = real1 * real2;				// Realizamos la operacion

	cout << resultado << "\n\n";			/* No nos va a mostrar el resultado correctamente, nos lo va a mostrar sin decimales
														porque los decimales son 02 y al redondear se queda en 0. */
	
	// Solucion
	
	cout.precision(2);						// Añadimos esta linea para indicarque que queremos que nos lo muestre con 2 decimales.
	cout << fixed;								// Añadimos esta linea para que nos muestre el resultado conrrectamente y no con la e^...
	resultado = real1 * real2;				// Realizamos la operacion

	cout << resultado << "\n\n";
	

}

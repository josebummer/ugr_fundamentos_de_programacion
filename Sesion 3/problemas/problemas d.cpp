/* Indicar si se produce un problema de precisión o de desbordamiento en los siguientes ejemplos 
indicando cuál será el resultado final de las operaciones. */

#include <iostream>

using namespace std;

int main (){
	
	//d)
	double resultado, real1, real2; 			// Declaramos las variables.
	
	real1 = 123456789.1;							// Damos valor a las variables.
	real2 = 123456789.2;
	
	resultado = real1 * real2;					// Realizamos la operacion
	
	cout << resultado << "\n\n";			   // Nos va a mostrar un resultado erroneo porque el tipo double no soporta tantos numeros.
	
	// Solucion
	
	double long resultado2, real3, real4; 		// Declaramos las variables con el tipo double long para que cojan mas caracteres.
	
	real3 = 123456789.1;							// Damos valor a las variables.
	real4 = 123456789.2;
			
	cout << fixed;								// Añadimos esta linea para que nos muestre el resultado conrrectamente y no con la e^...
	resultado2 = real3 * real4;				// Realizamos la operacion

	cout << resultado2 << "\n\n";
	

}

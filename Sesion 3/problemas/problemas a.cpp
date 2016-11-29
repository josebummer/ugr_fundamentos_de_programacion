/* Indicar si se produce un problema de precisión o de desbordamiento en los siguientes ejemplos 
indicando cuál será el resultado final de las operaciones. */

#include <iostream>

using namespace std;

int main (){
	
	// a)
	int chico, chico1, chico2; 			// Declaramos las variables
	chico1 = 123456789; 						//Damos un valor a la primera variable
	chico2 = 123456780; 						// Damos valor a la segunda variable
	chico = chico1 * chico2; 				// Realizamos la operacion

	cout << chico << "\n\n"; 				/*Nos va a mostrar un resultado no real, ya que el tipo int no soporta tantos 
														caracteres como se necesitan para mostrar este numero, necesitariamos usar el long long
														para que funcionase. */
	
	// Solucion
	long long grande, chico3, chico4;	// Creamos las variable de tipo long long	
					
	chico3 = 123456789; 						//Damos un valor a la primera variable
	chico4 = 123456780;			
		
	grande = chico3 * chico4; 		

	cout << grande << "\n\n";				// Ya va a mostrarnos el resultado correctamente.

}

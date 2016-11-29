/* Indicar si se produce un problema de precisión o de desbordamiento en los siguientes ejemplos 
indicando cuál será el resultado final de las operaciones. */

#include <iostream>

using namespace std;

int main (){
	
	//b)
	long grande;								// Declaramos una variable numerica grande
	int chico1, chico2;						// Declaramos otras variables mas pequeñas
	 						
	chico1 = 123456789; 						//Damos valores a las variables pequeñas
	chico2 = 123456780; 
	
	grande = chico1 * chico2;				// Ejecutamos la sentencia
	
	cout << grande << "\n\n";				// Como em el apartado a no nos va a mostrar el numero completo, necesitamos long long
	
	// Solucion
	long long grande2, chico3, chico4;	// Creamos las variable de tipo long long	
					
	chico3 = 123456789; 						//Damos un valor a la primera variable
	chico4 = 123456780;			
		
	grande2 = chico3 * chico4; 		

	cout << grande2 << "\n\n";				// Ya va a mostrarnos el resultado correctamente.

}

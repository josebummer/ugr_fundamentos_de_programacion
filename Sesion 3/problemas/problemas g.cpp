/* Indicar si se produce un problema de precisión o de desbordamiento en los siguientes ejemplos 
indicando cuál será el resultado final de las operaciones. */

#include <iostream>

using namespace std;

int main() {

	float chico;								// Declaramos las variables
	double grande;
	
	grande = 2e+150;							// Le damos valor a las variables.
	chico = grande;

	cout << chico << "\n\n";				/* Nos va a mostrar un error ya que la variable chico es float y la variable grande es 
														double, lo que significa que permite mas numero de decimales y por eso no cogen en la variable chico.*/
														
	// Solucion
	
	double chico2,grande2; 					// Declaramos las variables con el tipo double long para que cojan mas caracteres.
	
	grande2 = 2e+150;							// Damos valor a las variables.
	chico2 = grande;
										
	cout << chico2 << "\n\n";	
	
	system("pause");

}

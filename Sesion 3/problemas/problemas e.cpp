/* Indicar si se produce un problema de precisi�n o de desbordamiento en los siguientes ejemplos 
indicando cu�l ser� el resultado final de las operaciones. */

#include <iostream>

using namespace std;

int main (){
	
	//e)
	double real, otro_real;
	
	real = 2e34;
	otro_real = real + 1;
	otro_real = otro_real - real;
	
	cout << fixed;
	cout << real << "\n";
	cout << otro_real << "\n\n";
	
	// Solucion
	
}

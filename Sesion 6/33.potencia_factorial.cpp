/*Calcular mediante un programa en C++ la función potencia x^n, y la función factorial
n! con n un valor entero y x un valor real. No pueden usarse las funciones de la
biblioteca cmath.*/

#include <iostream>

using namespace std;

int main(){

	int nentero,i,factorial;					// Ponemos las variables
	double xreal,potencia=1;
	
	cout << "Introduce un numero entero: ";		//Pedimos los datos de entrada
	cin >> nentero;
	cout << "Introduce un numero real: ";
	cin >> xreal;
	
	for(i=0;i<nentero;i++)							//Sacamos la potencia multimplicando el numero real tantas veces como indique el nentero.
		potencia *= xreal;
	
	factorial=nentero;								//Sacamos el factorial multimplicando el numero entero por los numeros que van antes de el hasta el 2.
	for(i=2;i<nentero;i++)
		factorial *= i;
		
	cout << "\nLa potencia de " << xreal << " elevado a " << nentero << " es: " << potencia << "\n";			//Mostramos el resultado
	cout << "El facorial de " << nentero << " es: " << factorial << "\n\n"; 
	
system("pause");
}

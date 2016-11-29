/*Sobre la soluci�n del ejercicio 19 de esta relaci�n de problemas, se pide lo siguiente.
Supondremos que s�lo pueden introducirse intereses enteros (1, 2, 3, etc). Se pide
calcular el capital obtenido al t�rmino de cada a�o, pero realizando los c�lculos para
todos los tipos de inter�s enteros menores o iguales que el introducido (en pasos de
1). Por ejemplo, si el usuario introduce un inter�s igual a 5 y un n�mero de a�os igual
a 3, hay que mostrar el capital ganado al t�rmino de cada uno de los tres a�os a un
inter�s del 1 %, a continuaci�n, lo mismo para un inter�s del 2% y as� sucesivamente
hasta llegar al 5 %. El programa debe mostrar una salida del tipo:*/

#include <iostream>

using namespace std;

int main(){
		
	double capital, interes,total;														//Introducimos las variables
	int anios,i,j;
	
	cout << "Introduce el capital: ";													//Pedimos los datos para darle valor a las variables.
	cin >> capital;
	cout << "Introduce el interes: ";
	cin >> interes;
	cout << "Introduce los a�os: ";
	cin >> anios;
	
	for(j=1;j<=interes;j++){																//Realizamos un bucle para comprobar el capital con todos los intereses posibles.
		total=capital;
		cout << "\n\nCalculo realizado al " << j << "%\n";
		for (i=1;i<=anios;i++){																//Creamos otr bucle anidado que nos calculara el capital a mostrar.
			
			total += capital * j /100;	
			cout << "Total en el a�o numero " << i << ": " << total << ".\n";			//Mostramos el resultado.

		}
	}
}

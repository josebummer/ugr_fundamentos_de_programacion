/*Sobre la solución del ejercicio 19 de esta relación de problemas, se pide lo siguiente.
Supondremos que sólo pueden introducirse intereses enteros (1, 2, 3, etc). Se pide
calcular el capital obtenido al término de cada año, pero realizando los cálculos para
todos los tipos de interés enteros menores o iguales que el introducido (en pasos de
1). Por ejemplo, si el usuario introduce un interés igual a 5 y un número de años igual
a 3, hay que mostrar el capital ganado al término de cada uno de los tres años a un
interés del 1 %, a continuación, lo mismo para un interés del 2% y así sucesivamente
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
	cout << "Introduce los años: ";
	cin >> anios;
	
	for(j=1;j<=interes;j++){																//Realizamos un bucle para comprobar el capital con todos los intereses posibles.
		total=capital;
		cout << "\n\nCalculo realizado al " << j << "%\n";
		for (i=1;i<=anios;i++){																//Creamos otr bucle anidado que nos calculara el capital a mostrar.
			
			total += capital * j /100;	
			cout << "Total en el año numero " << i << ": " << total << ".\n";			//Mostramos el resultado.

		}
	}
}

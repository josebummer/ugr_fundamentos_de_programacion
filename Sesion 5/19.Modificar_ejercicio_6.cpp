/*Modifiquemos el ejercicio 6 del capital y los intereses de la primera relación. Supongamos
ahora que se quiere reinvertir todo el dinero obtenido (el original C más los
intereses producidos) en otro plazo fijo a un año y así, sucesivamente. Construid un
programa para que lea el capital, el interés y un número de años N, y calcule e imprima
todo el dinero obtenido durante cada uno de los N años, suponiendo que todo
lo ganado (incluido el capital original C) se reinvierte a plazo fijo durante el siguiente
año. El programa debe mostrar una salida del tipo:*/

#include <iostream>

using namespace std;

int main(){

	double capital, interes;										//Declaramos las variables
	int anios,i=1;
	
	cout << "Introduce el capital: ";							//Pedimos los datos de entrada
	cin >> capital;
	cout << "Introduce el interes: ";
	cin >> interes;
	cout << "Introduce los años: ";
	cin >> anios;
	
	while (i<=anios){																				//Realizamos el condicional
	
		cout << "Total en el año numero " << i << ": " << capital << ".\n";		//Mostramos por pantalla año por año
		capital += capital * (interes/100);													//Realizamos la operacion
		i++;	
	
	}
	
	system("pause");
}
